// ============================================================================
// alloc.cpp
//
// Fixed-size memory pool allocator.
//
// Design goals:
//   - O(1) allocation
//   - O(1) deallocation
//   - No malloc/free in the hot path
//   - Cache-friendly contiguous backing storage
//   - Correct basic alignment
//   - Simple benchmark against malloc/free
//
// Intended workloads:
//   - Network packet objects
//   - Game entities
//   - ECS components
//   - Fixed-size request objects
//   - High-frequency temporary objects
//
// Build:
//   g++ -std=c++20 -O3 -march=native -DNDEBUG alloc.cpp -o alloc
//
// Run:
//   ./alloc
// ============================================================================

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <new>
#include <chrono>
#include <vector>
#include <algorithm>


// ============================================================================
// Compiler optimization barrier
//
// We need to prevent the compiler from treating the benchmarked work as
// completely irrelevant.
// ============================================================================

#if defined(__GNUC__) || defined(__clang__)

inline void do_not_optimize(void* pointer) noexcept {
    asm volatile("" : : "g"(pointer) : "memory");
}

inline void memory_barrier() noexcept {
    asm volatile("" : : : "memory");
}

#elif defined(_MSC_VER)

#include <intrin.h>

inline void do_not_optimize(void* pointer) noexcept {
    _ReadWriteBarrier();
    (void)pointer;
}

inline void memory_barrier() noexcept {
    _ReadWriteBarrier();
}

#else

inline void do_not_optimize(void* pointer) noexcept {
    (void)pointer;
}

inline void memory_barrier() noexcept {}

#endif


// ============================================================================
// FixedPool
//
// A fixed-size free-list allocator.
//
// Memory layout:
//
//     +---------+---------+---------+---------+
//     | Block 0 | Block 1 | Block 2 | Block 3 |
//     +---------+---------+---------+---------+
//
// Each free block stores a pointer to the next free block:
//
//     free_list
//         |
//         v
//     [Block] -> [Block] -> [Block] -> nullptr
//
// allocate():
//
//     node = free_list
//     free_list = node->next
//     return node
//
// deallocate():
//
//     node->next = free_list
//     free_list = node
//
// Both operations are O(1).
// ============================================================================

class FixedPool {
private:

    struct FreeNode {
        FreeNode* next;
    };


    // Raw backing storage.
    std::byte* memory_ = nullptr;


    // Head of the singly linked free list.
    FreeNode* free_list_ = nullptr;


    // Actual size of each block.
    std::size_t block_size_ = 0;


    // Number of blocks.
    std::size_t block_count_ = 0;


    // Number of currently available blocks.
    std::size_t free_count_ = 0;


    // Round a size upward to satisfy alignment.
    static constexpr std::size_t align_up(
        std::size_t value,
        std::size_t alignment
    ) noexcept {

        return (value + alignment - 1) &
               ~(alignment - 1);
    }


public:

    // ------------------------------------------------------------------------
    // Constructor
    // ------------------------------------------------------------------------

    FixedPool(
        std::size_t requested_block_size,
        std::size_t block_count
    )
        : block_count_(block_count),
          free_count_(block_count)
    {
        if (block_count == 0) {
            throw std::invalid_argument(
                "FixedPool requires at least one block"
            );
        }


        // Every block must at least be able to store FreeNode::next.
        block_size_ = std::max(
            requested_block_size,
            sizeof(FreeNode)
        );


        // Align each block.
        block_size_ = align_up(
            block_size_,
            alignof(std::max_align_t)
        );


        const std::size_t total_size =
            block_size_ * block_count_;


        // Allocate aligned backing memory.
        memory_ = static_cast<std::byte*>(
            ::operator new(
                total_size,
                std::align_val_t(alignof(std::max_align_t))
            )
        );


        // Build the free list.
        //
        // We link every block during initialization so allocation requires
        // only two pointer operations.

        for (std::size_t i = 0; i < block_count_; ++i) {

            auto* block =
                reinterpret_cast<FreeNode*>(
                    memory_ + i * block_size_
                );

            block->next = free_list_;

            free_list_ = block;
        }
    }


    // ------------------------------------------------------------------------
    // Destructor
    // ------------------------------------------------------------------------

    ~FixedPool() noexcept {

        ::operator delete(
            memory_,
            std::align_val_t(alignof(std::max_align_t))
        );
    }


    // ------------------------------------------------------------------------
    // Prevent accidental copying.
    // ------------------------------------------------------------------------

    FixedPool(const FixedPool&) = delete;

    FixedPool& operator=(
        const FixedPool&
    ) = delete;


    // ------------------------------------------------------------------------
    // Move support.
    // ------------------------------------------------------------------------

    FixedPool(FixedPool&& other) noexcept
        : memory_(other.memory_),
          free_list_(other.free_list_),
          block_size_(other.block_size_),
          block_count_(other.block_count_),
          free_count_(other.free_count_)
    {
        other.memory_ = nullptr;
        other.free_list_ = nullptr;
        other.block_size_ = 0;
        other.block_count_ = 0;
        other.free_count_ = 0;
    }


    FixedPool& operator=(
        FixedPool&& other
    ) noexcept {

        if (this == &other) {
            return *this;
        }

        ::operator delete(
            memory_,
            std::align_val_t(alignof(std::max_align_t))
        );

        memory_ = other.memory_;
        free_list_ = other.free_list_;
        block_size_ = other.block_size_;
        block_count_ = other.block_count_;
        free_count_ = other.free_count_;

        other.memory_ = nullptr;
        other.free_list_ = nullptr;
        other.block_size_ = 0;
        other.block_count_ = 0;
        other.free_count_ = 0;

        return *this;
    }


    // ------------------------------------------------------------------------
    // allocate
    //
    // Hot path:
    //
    //     1. Read free_list_
    //     2. Move free_list_ to node->next
    //     3. Return node
    // ------------------------------------------------------------------------

    [[nodiscard]]
    inline void* allocate() {

        FreeNode* node = free_list_;

        if (node == nullptr) {
            throw std::bad_alloc();
        }

        free_list_ = node->next;

        --free_count_;

        return node;
    }


    // ------------------------------------------------------------------------
    // deallocate
    //
    // Push the returned block onto the front of the free list.
    // ------------------------------------------------------------------------

    inline void deallocate(void* pointer) noexcept {

        if (pointer == nullptr) {
            return;
        }

        auto* node =
            static_cast<FreeNode*>(pointer);

        node->next = free_list_;

        free_list_ = node;

        ++free_count_;
    }


    // ------------------------------------------------------------------------
    // Introspection
    // ------------------------------------------------------------------------

    [[nodiscard]]
    constexpr std::size_t block_size() const noexcept {
        return block_size_;
    }


    [[nodiscard]]
    constexpr std::size_t capacity() const noexcept {
        return block_count_;
    }


    [[nodiscard]]
    constexpr std::size_t available() const noexcept {
        return free_count_;
    }


    [[nodiscard]]
    constexpr bool empty() const noexcept {
        return free_list_ == nullptr;
    }
};


// ============================================================================
// Benchmark configuration
// ============================================================================

constexpr std::size_t ALLOCATION_SIZE = 64;

constexpr std::size_t ITERATIONS =
    10'000'000;


// ============================================================================
// Benchmark helper
// ============================================================================

template <typename Allocate, typename Deallocate>
void benchmark(
    const char* name,
    Allocate&& allocate,
    Deallocate&& deallocate
) {

    // Warm up a little.
    //
    // This is not intended to make results magically perfect, but prevents
    // the first measured operation from being the only cold-cache operation.

    for (std::size_t i = 0; i < 10'000; ++i) {

        void* pointer = allocate();

        do_not_optimize(pointer);

        deallocate(pointer);
    }


    memory_barrier();


    const auto start =
        std::chrono::steady_clock::now();


    for (
        std::size_t i = 0;
        i < ITERATIONS;
        ++i
    ) {

        void* pointer = allocate();

        do_not_optimize(pointer);

        deallocate(pointer);
    }


    memory_barrier();


    const auto end =
        std::chrono::steady_clock::now();


    const auto duration =
        std::chrono::duration_cast<
            std::chrono::nanoseconds
        >(end - start);


    const double nanoseconds_per_operation =
        static_cast<double>(
            duration.count()
        ) / ITERATIONS;


    const double operations_per_second =
        1'000'000'000.0 /
        nanoseconds_per_operation;


    std::cout
        << name
        << "\n"
        << "  Total: "
        << duration.count()
        << " ns\n"
        << "  Time:  "
        << nanoseconds_per_operation
        << " ns/op\n"
        << "  Rate:  "
        << operations_per_second
        << " ops/sec\n\n";
}


// ============================================================================
// Bulk allocation benchmark
//
// Allocate everything first, then free everything.
//
// This measures a different workload from:
//
//     allocate -> free
//
// The allocator has to handle an increasing number of simultaneously-live
// allocations.
// ============================================================================

template <typename Allocate, typename Deallocate>
void benchmark_bulk(
    const char* name,
    Allocate&& allocate,
    Deallocate&& deallocate,
    std::size_t count
) {

    std::vector<void*> pointers;

    pointers.reserve(count);


    const auto start =
        std::chrono::steady_clock::now();


    for (
        std::size_t i = 0;
        i < count;
        ++i
    ) {

        void* pointer = allocate();

        do_not_optimize(pointer);

        pointers.push_back(pointer);
    }


    for (void* pointer : pointers) {
        deallocate(pointer);
    }


    const auto end =
        std::chrono::steady_clock::now();


    const auto duration =
        std::chrono::duration_cast<
            std::chrono::nanoseconds
        >(end - start);


    const double total_operations =
        static_cast<double>(count) * 2.0;


    const double nanoseconds_per_operation =
        static_cast<double>(
            duration.count()
        ) / total_operations;


    std::cout
        << name
        << " (bulk)\n"
        << "  Total: "
        << duration.count()
        << " ns\n"
        << "  Time:  "
        << nanoseconds_per_operation
        << " ns/op\n\n";
}


// ============================================================================
// Example object.
//
// This represents the kind of fixed-size object the allocator is intended
// for. You could replace this with a network packet structure.
// ============================================================================

struct Packet {

    std::byte data[64];

};


// ============================================================================
// Main
// ============================================================================

int main() {

    std::cout
        << "========================================\n"
        << " Custom Allocator Benchmark\n"
        << "========================================\n\n";


    std::cout
        << "Allocation size: "
        << ALLOCATION_SIZE
        << " bytes\n";

    std::cout
        << "Iterations: "
        << ITERATIONS
        << "\n\n";


    // ------------------------------------------------------------------------
    // Create the pool.
    //
    // For the immediate allocate/free benchmark, a small pool is sufficient.
    //
    // For bulk allocation we need enough blocks for every simultaneous
    // allocation.
    // ------------------------------------------------------------------------

    FixedPool pool(
        ALLOCATION_SIZE,
        ITERATIONS
    );


    // ------------------------------------------------------------------------
    // malloc/free benchmark
    // ------------------------------------------------------------------------

    benchmark(
        "malloc/free",

        []() -> void* {

            return std::malloc(
                ALLOCATION_SIZE
            );

        },

        [](void* pointer) {

            std::free(pointer);

        }
    );


    // ------------------------------------------------------------------------
    // Custom pool benchmark
    // ------------------------------------------------------------------------

    benchmark(
        "FixedPool",

        [&pool]() -> void* {

            return pool.allocate();

        },

        [&pool](void* pointer) {

            pool.deallocate(pointer);

        }
    );


    // ------------------------------------------------------------------------
    // Bulk benchmark.
    // ------------------------------------------------------------------------

    constexpr std::size_t BULK_COUNT =
        1'000'000;


    benchmark_bulk(
        "malloc/free",

        []() -> void* {

            return std::malloc(
                ALLOCATION_SIZE
            );

        },

        [](void* pointer) {

            std::free(pointer);

        },

        BULK_COUNT
    );


    benchmark_bulk(
        "FixedPool",

        [&pool]() -> void* {

            return pool.allocate();

        },

        [&pool](void* pointer) {

            pool.deallocate(pointer);

        },

        BULK_COUNT
    );


    // ------------------------------------------------------------------------
    // Basic sanity test with Packet objects.
    // ------------------------------------------------------------------------

    {
        FixedPool packet_pool(
            sizeof(Packet),
            1024
        );


        void* raw =
            packet_pool.allocate();


        Packet* packet =
            new (raw) Packet();


        packet->data[0] =
            std::byte{42};


        // Explicitly destroy because we used placement new.
        packet->~Packet();


        packet_pool.deallocate(packet);
    }


    std::cout
        << "Benchmark complete.\n";


    return 0;
}

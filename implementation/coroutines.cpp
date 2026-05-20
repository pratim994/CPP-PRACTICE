#include <coroutine>
#include <iostream>

template<typename T>
struct Generator {
    struct promise_type {
        T current_value;

        Generator get_return_object() {
            return Generator{
                std::coroutine_handle<promise_type>::from_promise(*this)
            };
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        std::suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }

        void return_void() {}
        void unhandled_exception() {
            std::exit(1);
        }
    };

    std::coroutine_handle<promise_type> handle;

    Generator(std::coroutine_handle<promise_type> h)
        : handle(h) {}

    ~Generator() {
        handle.destroy();
    }

    bool next() {
        handle.resume();
        return !handle.done();
    }

    T value() {
        return handle.promise().current_value;
    }
};

Generator<int> counter() {
    for (int i = 1; i <= 5; i++) {
        co_yield i;
    }
}


int main() {
    auto gen = counter();

    while (gen.next()) {
        std::cout << gen.value() << '\n';
    }
}

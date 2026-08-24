#include <iostream>
#include <utility>
#include <cstdint>

template<typename T>
class unique_ptr {
private:
    T* ptr = nullptr;

public:
    explicit unique_ptr(T* p = nullptr) noexcept
        : ptr(p)
    {
        std::cout << "Constructor called\n";
    }

    ~unique_ptr() {
        delete ptr;
        std::cout << "Destructor called\n";
    }

    // Copying is forbidden
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // Move constructor
    unique_ptr(unique_ptr&& other) noexcept
        : ptr(other.ptr)
    {
        std::cout << "Move constructor called\n";
        other.ptr = nullptr;
    }

    // Move assignment
    unique_ptr& operator=(unique_ptr&& other) noexcept {

        std::cout << "Move assignment called\n";

        if (this != &other) {

            // Destroy the object we currently own
            delete ptr;

            // Take ownership
            ptr = other.ptr;

            // Remove ownership from source
            other.ptr = nullptr;
        }

        return *this;
    }

    T* operator->() const noexcept {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    explicit operator bool() const noexcept {
        return ptr != nullptr;
    }

    T* get() const noexcept {
        return ptr;
    }
};


class Java {
public:

    Java() {
        std::cout << "I hate java\n";
    }

    ~Java() {
        std::cout << "Java destroyed lol\n";
    }

    void hello() {
        std::cout << "hello from the other side!\n";
    }
};


int main() {

    std::cout << "Move constructor\n";

    unique_ptr<Java> up1(new Java());

    unique_ptr<Java> up2 = std::move(up1);

    if (!up1) {
        std::cout << "up1 is empty!\n";
    }

    if (up2) {
        up2->hello();
    }
}

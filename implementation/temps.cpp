#include <iostream>

// Recursive helper template
template <unsigned N, unsigned D>
struct IsPrimeHelper {
    static constexpr bool value =
        (N % D != 0) && IsPrimeHelper<N, D - 1>::value;
};

// Base case for recursion
template <unsigned N>
struct IsPrimeHelper<N, 1> {
    static constexpr bool value = true;
};

// Main prime-check template
template <unsigned N>
struct IsPrime {
    static constexpr bool value =
        (N >= 2) && IsPrimeHelper<N, N / 2>::value;
};

// Specializations for 0 and 1
template <>
struct IsPrime<0> {
    static constexpr bool value = false;
};

template <>
struct IsPrime<1> {
    static constexpr bool value = false;
};

int main() {
    constexpr unsigned number = 29;

    if constexpr (IsPrime<number>::value) {
        std::cout << number << " is prime\n";
    } else {
        std::cout << number << " is not prime\n";
    }

    return 0;
}

#include <iostream>
#include <chrono>


auto VariadicMultiply()
{
	return 1;
}

template <typename T1, typename... T>
auto VariadicMultiply(T1 t, T... ts){
	return t*VariadicMultiply(ts...);
}


int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	std::cout << VariadicMultiply<int,int>(2,2,2,2,2,2,2,2,2,2) << '\n';

	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

	std::cout << duration << "IN nanoseconds \n";
	return 0;
}

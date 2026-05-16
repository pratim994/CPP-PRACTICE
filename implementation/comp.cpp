#include <iostream>
#include <chrono>
#include <algorithm>


// comparison to check what is faster std::move or xor for swapping variables

template <typename T>
void swap(T a, T b)
{
	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);

}

void swapXor(int c, int d)
{
	c ^= d;
	
	d ^= c;

	c ^= d;

}
int main()
{

//	auto start = std::chrono::high_resolution_clock::now();

//	swap(1001, 1002);

//	auto stop = std::chrono::high_resolution_clock::now();

//	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

//	std::cout << time << '\n';


	auto start =  std::chrono::high_resolution_clock::now();

	swapXor(1001, 1002);

	auto stop = std::chrono::high_resolution_clock::now();

	auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

	std::cout << dur << '\n';
}

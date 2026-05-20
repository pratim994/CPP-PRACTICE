#include <iostream>
#include <future>
#include <coroutine>

using namespace std;

int  async_add(int a, int b)
{
	return ([&this](){
		int c =a+b;
		return c;
			});

}


int  async_fib(int n)
{
	if(n <= 2)
		return 1;

	int a = 1;
	int b = 1;

	for(int i= 0; i < n-2; ++i)
	{
		int c = co_await  async_add(a,b);

		a= b;
		b= c;
	}

	co_return b;
}

int async_test()
{
	for(int i = 1; i < 10; ++i)
	{
		int ret = co_await async_fib(i);
		std::cout << "aync fibonacci :" << i << "returns "  << ret << '\n';

	}
}


int main()
{
	auto fut = async_test();

	fut.wait();

	return 0;
}


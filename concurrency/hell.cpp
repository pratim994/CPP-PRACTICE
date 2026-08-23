#include <iostream>
#include <thread>
#include <random>

void hello()
{
	std::cout << "hello concurrent world\n" ;


}

void print()
{
	std::random_device rd;

	std::mt19937 gen(rd());

	std::cout << "random generating thread in c++ " << gen << "\n";
}


int main(){

	//std::thread t(hello);
	//t.join();
	//
	
	std::thread t(print);
	int i = 10;
	while(i--){
	t.join();
	}


}

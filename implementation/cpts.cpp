#include <iostream>
#include <concepts>

/*
 compile time predicate to test our type 
 make sure that we can use our templated function
 
 */



template<typename T>
requires std::integral<T >
void Print(T value){
	std::cout << "the value is : " << value << '\n';
}


template<typename T>
requires std::integral<T>

bool IsPrime(T number) noexcept {
	
	for(int d = 2; d*d <= number; d++ ){
		if(number%d == 0)
			return false;
	}

	return true;
}
			

int main()
{
	Print<int>(69);
	
	 std::cout << std::boolalpha << IsPrime<bool>(12) << '\n';
	return 0;
}

#include <bits/stdc++.h>

using namespace std;


int main(){


	ios::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	int n, k;

	scanf("%d%d", &n, &k);


	int prime[1000] = {3,5}, count(2);

	for(int number =7; number <= n && k!= 0; number +=2)
	{

		int  i =0;

		while(i <  count &&  number % prime[i]!= 0 ){
			++i;
		}

		if(i == count){

			for(int j = 1; j < count; ++j){
				if(prime[j] + prime[j-1] +1 == number){
					k -= 1;
					break;
				}
			}
			prime[count++] = number;

	}

	// check if there are prime k prime number in the range of 2 to n , that can be expressed as a sum of 3 integers , 2 previous primes and 1 
	// for ex 13 = 5+7+1 and 19 = 13+5+1
	//
	// so any no greater or eq to 11 can be represented as such , as 11 = 7+3 +1 , just add to 2 to and you have 13 , then you can have 17 = 13+3 +1 and 19 and 23 = 19+3+1
	//
	// similary 23+5 +1 = 29	
	
	}

	printf(k == 0 ? "YES\n" : "NO\n");

	return 0;
}

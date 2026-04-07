#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#include <chrono>

constexpr int coins(std::vector<int> &coins, int amount){

		std::vector<int> dp(++amount);

		dp[0] = 0;

		for(int i = 1; i < amount; i++)
		{
			std::sort(begin(coins), end(coins));
		
			dp[i] = INT_MAX;

			for(int c : coins)
			{
				if(i-c < 0 ) break;

				if(dp[i-c] != INT_MAX) dp[i] = std::min(dp[i], 1+dp[i-c]);
			}
		}

	return dp[--amount] == INT_MAX ? -1 : dp[amount];


}



int main() {


	std::cin.tie(nullptr);

	std::cout.tie(nullptr);

	
	int n, amt;

	printf("enter the size of the array\n");

	scanf("%d" , &n);

	printf("enter denominations\n");

	std::vector<int> arr(n);

	for(auto &i : arr) scanf("%d", &i);

	printf("enter the amount\n");

	scanf("%d", &amt);

	auto  start = std::chrono::high_resolution_clock::now();

	int result = coins(arr, amt);

        auto stop = std::chrono::high_resolution_clock::now();

	auto  latency = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

	printf("Minimum coins needed %d\n", result); 
	printf("%ld ns\n" , latency.count());

}

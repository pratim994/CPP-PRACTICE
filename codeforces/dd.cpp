#include <bits/stdc++.h>
#include <chrono>



int main()
{
	std::ios_base::sync_with_stdio(0); std::cin.tie(0) ; std::cout.tie(0);

	int t, n;

	std::cin >> t ;

	while(t--){
	
		int ans = 0;
		std::cin >> n;

		std::vector<int> arr(n);

		for(auto &i : arr) std::cin >> i ;


		for(int i = 0 ; i < n; i++)
			if(arr[i] > 1 ) ans += arr[i];
			
			if(arr.back() ==1 ) ans++;	
		 

		std::cout << ans << '\n';
		
	
	}	
}

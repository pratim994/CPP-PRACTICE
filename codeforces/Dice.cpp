// cses list first question lol, let good things begin


#include <bits/stdc++.h>

using namespace std;



int main(){

	int n;

	cin >> n;

	int ans  =0;

	// dynamic programming problem 
	// or n = 3 , how many combinations of values in the range 1 t 6 ; ie in a dice can create the given given number
	

	vector<int> dp(n+1);

	dp[n] =1;


	const int mod = 1e9 + 7;
	for(int i =n-1; i >= 0; i--){
			for(int j= 0; j < 6; j++)
			{
				if(j <= n-i){
				dp[i] = (dp[i] + dp[i+j])%mod;
				}
	}
	
}		


cout << dp[0] << endl;

}


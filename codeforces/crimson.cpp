#include <bits/stdc++.h>

using namespace std;



int32_t main()

{
	int t;

	cin >> t;

	while(t--){
		
		int n;

		cin >> n;

		long long  ans = 0;

		for(long long b = 1; b <= n; b++){

			ans  += (n/b)*(n/b);

		}

		cout << ans << '\n';

	}



}

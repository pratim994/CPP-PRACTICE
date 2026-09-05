#include <bits/stdc++.h>
using namespace std;

void solve(){

	int n;

	cin >> n;
	vector<int> a(n);


	// entre vous le logic 
	
	// now I get it perfect K  only exists 
	// if n is even and the maximum element at even positions is strictly less than the minimum element at odd positions 
	
	long long L = 0, R = 1e9+7;

	for(int i = 1; i <= n; ++i){
		long long w;

		cin >> w;
		if(i&1)
			R = min(R,w);
		else
			L = max(L,w);

	}

	cout << (n%2 == 0 && L+2 <= R ? "YES" : "NO") << "\n";

}


int main(){

	int t;
	cin >> t;
	while(t--){
		
		solve();
	

	}

}


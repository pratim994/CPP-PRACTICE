#include <bits/stdc++.h>
using namespace std;


bool  good(const vector<int>& x, const vector<int>& y, int n, int k){

	for(int i = 0; i<n;i++){
		if(x[i] <=  y[(i+k)%n]){
			return false;
		}

	}
return true;
}



int main(){
	int t =0;	cin >> t;
	while(t--){
		int n; cin >> n;
			vector<int> a(n), b(n), c(n);

			for(int i = 0 ; i<n;i++) cin >> a[i];
			for(int i=0; i<n; i++) cin >> b[i];
			for(int i =0; i<n; i++) cin >> c[i];

			long long k1 =0, k2 =0;

			for(int i =0; i<n; i++){
				if(good(b, a, n, i)) k1++;
				if(good(c, b, n, i)) k2++;
			}
			cout << (k1*k2*n) <<'\n';
	}
	return 0;
}



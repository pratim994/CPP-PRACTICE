#include <bits/stdc++.h>
using namespace std;



void solve(){

	int n;

	cin >> n;

	int y =1;
	while(n >0){

		y *=10;
		n/=10;
	}

	cout << y+1 << '\n';


}


int main(){
	
	int t;

	cin >> t;

	while(t--){

		solve();

	}


}

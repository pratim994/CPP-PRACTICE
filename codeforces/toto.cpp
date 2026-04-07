
#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define nline endl;


void solve(){
	ll n;
	cin >> n;
	ll arr[n];


	unordered_map<ll , ll> hmap;
	for(int i = 0; i< n; i++){
		cin >> arr[i];
		hmap[arr[i]]++;
			}

	ll maxFreq =0;
	for(auto itr : hmap)
		maxFreq =  max(maxFreq, itr.second);
	cout <<(n -  maxFreq)<< nline;


}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t = 1;
	cin >> t;
	while(t--){
		solve();

	}
	return 0;

	}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		string a , b;
		ll  ans  =0;
		cin >> a >> b ;
		bool ok = true;
		for(int k = 0; k < 2; k++){
			vector<ll> al, bl;
			for(int i = k; i < n; i+=2){
				if(a[i] == '1') al.push_back(i);
				if(b[i] == '1') bl.push_back(i);
			}
		if(al.size() != bl.size() ){
			ok  = false;
			break;
		}
			for(int i =0; i < al.size(); i++) ans += abs(al[i]-bl[i]);
	}
		if(!ok) cout << -1 << endl;
		else cout << ans/2 << '\n';
}
}

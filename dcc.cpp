
#include <bits/stdc++.h>
using namespace std;

void solve(){
	string n; cin >> n;
	vector<char> sf;
	int a = 0, b = 0;
	for(char c : n){
		sf.push_back(c);
	}
	for(int i = 0; i<sf.size(); i++){
		if(sf[i]!= '+'){
			a = sf[i] - '0';
			b= sf[i+1] - '0';
		}


}
	cout << a+b << endl;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t; 
	while(t--)
		void solve();
	return 0;
}

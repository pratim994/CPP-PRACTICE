#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){

		int n;

		cin >> n;

		string s;

		cin >> s;
		// good question as std:: unique won't work 
		// I have to find the minimimum value of the compressed string
		// at first I thought I can just pass this in std::unique and game over but no .
		// they mean't contiguosz not unique characters 
		// and you can only remove one characater
		
		int ans = 1, x =0;

		for(int i = 1; i < s.size(); i++){

			if(s[i] != s[i-1]){
				ans++;	
			}
			if(i == n-1){
				break;}

			if(s[i-1] != s[i] && s[i] != s[i+1]){
				if(s[i-1] == s[i+1] ) x =2;

					x = max(x, 1);
			}

		}
		cout << ans -x << '\n';

		}




	return 0;
}

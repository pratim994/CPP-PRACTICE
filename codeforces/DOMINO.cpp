#include <bits/stdc++.h>

using namespace std;


int  solve(const string &s, int parity){
	
	int ways = 0;


	for(int start = 0; start <= 1; start++){
		
		bool ok = true;
		int step =0;

		for(int i = parity; i < (int)s.size(); i += 2){

			int expected = start^(step&1);

			if(s[i] != '?' && s[i] - '0' != expected) {

			ok = false;
			break;
			}

		step++;	
		
	}

		if (ok) ways++;
	}

	return ways;
}

	// amazing problem , really pushes your understanding of number theory and strings
	




int main(){

	const int MOD = 998244353;

	int t ;
	cin >> t;
	while(t--){
		int n;

		cin >> n;
		string s;
		cin >> s;


		int e = solve(s, 0);
		int o = solve(s,1);

		cout  << (1LL*e*o)%MOD  << '\n';
	}

return 0;
}



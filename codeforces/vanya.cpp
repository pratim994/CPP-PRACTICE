//solution to codeforces 677A 

#pragma GCC optimize("03")

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, h;

	cin >> n >> h;

	vector<int> ans(n);

	for(auto &i :  ans) cin >> i;

	int cnt =0;

	for(auto &i :  ans){
		
		if(i > h){
			cnt += 2;
		}
		else cnt++;

	}

	cout << cnt << '\n';

	return 0;

}



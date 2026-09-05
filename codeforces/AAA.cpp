
#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n ,k;
	string s;
	cin >> n >> k;
	cin >> s;
	int ans = 0;


	// no o fields is n 
	// and no of farms is n/k
	// no of farms == no of schools
	// if s[i] == 1
	// field is owned by nhoj and we need to increment the counter
	// so the question is essentially abs(cnt of zeroes - n/k)
	// also there should be aling ment like 1, 2 ,  .. k 
	
	for(int i = 0; i < n; i+=k){
		
		bool one = true;

		for(int j = i; j < i+k; ++j){
			if(s[j] == '0'){

				one = false;
				break;
			}

		}

		if(one)
			++ans;
	}


	cout << ans << '\n';
}


int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		solve();
	}


}

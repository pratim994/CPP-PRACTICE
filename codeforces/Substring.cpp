#include <bits/stdc++.h>

using namespace std;


void solve(){
	
	string s;

	scanf("%s", &s);

	int sum = 0;

	for(int i = 0; i +1 < n; i+=2)
	{
		sum += atoi(s.substr(i,2));
	}

	cout << sum << '\n';
}


int main()
{

	int t;

	scanf("%d", &t);


	while(t--)
	{

		solve();
	}
	return 0;
}

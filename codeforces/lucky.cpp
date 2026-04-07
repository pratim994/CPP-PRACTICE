#include <bits/stdc++.h>

using namespace std;


int main()
{
	long long n;

	 cin >> n;

	 //so no of 4s and 7s must be either 4 or 7 in given stream of long 
	 //then it is nearly lucky 
	  

	 string s = to_string(n);

	int cntL = 0;

	 for(char c : s)
		if(c == '4'  || c == '7')
			cntL++;

	if((cntL==4 || cntL == 7) && cntL > 0)
		cout << "YES\n";

	else 
		cout << "NO\n";

}



// solution for 110 A codeforces


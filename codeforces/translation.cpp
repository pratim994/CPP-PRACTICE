#include<bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;


int main(){

	string s1, s2 ;

	cin >> s1 >> s2;

	reverse(s1.begin(), s1.end());

	if(s1 == s2) cout << "YES\n";

	else cout << "NO\n";

	
	return 0;
}


//valid anagrams problems 
//reverse one string and find if they are equal

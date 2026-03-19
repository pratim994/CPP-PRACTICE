#include<bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;


int main(){

	int n;

	cin >> n;

	string s;

	cin >> s;

	int ant = 0 , dom = 0;
	for(char c : s){
		if(c == 'A')
			ant++;
		else 
			dom++;

	}

	if(dom > ant)
		cout << "Danik\n";
	if(dom < ant)
		cout << "Anton\n";
	if(ant == dom)
		cout << "Friendship\n";

	return 0;
}


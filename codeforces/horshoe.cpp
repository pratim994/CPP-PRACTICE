#include <bits/stdc++.h>

using namespace std;


int main()
{

	int a[4];

	for(int &i : a) cin >> i;
	sort(a,a+4);
	int cn= 0;
	for(int i = 1; i < 4;i++){
		if(a[i-1] == a[i]){
			cn++;
		}
	}

	cout << cn  << '\n';
}

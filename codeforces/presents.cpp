#include <bits/stdc++.h>

using namespace std;



int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	scanf("%d", &n);

	std::vector<int> arr(n+1);

	for(int i =1; i <= n; i++){

		cin >> m;

		arr[m] = i;


	}
	
	cout <<  arr[1] << " ";

	for(int i = 2; i <= n; i++){

		cout << arr[i] << " ";

	}
	cout << endl;
	return 0;
}

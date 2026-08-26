#include <bits/stdc++.h>
using namespace std;
int main(){


	int t;

	cin >> t;

	while(t--){
		int n;
		cin >> n;
		
		bool flag = true;

		for(int i =2; i < n+1; i++){
			if((n+1)%i == 0){
				flag = false;
				break;
			}
		}

		if(!flag){
			cout << "No" << '\n';
		}
		else {
			cout << "Yes" << '\n';
		}

	}



	return 0;
}

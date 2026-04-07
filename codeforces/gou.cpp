
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 3;
	int abc[3];
	while(n--){
		cin >> abc[n];

		int x = sizeof(abc)/sizeof(abc[0]);
		sort(abc, abc+x);
		if(abc[2] - abc[0] > 10){
			cout << "check again" <<std::endl;
		} else{



		 	cout << abc[1]<<std::endl;
		}
	}
	

	return 0;
}

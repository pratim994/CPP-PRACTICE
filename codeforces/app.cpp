
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while(t--){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] > arr[i+1]){
			count++;
	
		}
	}
	
	cout << count << endl;
}

	return 0;
}	

#include<bits/stdc++.h>
using namespace std;



int main() {
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> arr(n);

		for(auto &i :  arr) cin >> i;

		sort(arr.begin(), arr.end());

		arr.erase(unique(arr.begin(), arr.end()), arr.end());
		n = arr.size();

		int current = 0, best = 0;

		for(int i = 0; i < n; i++)
		{
			if(i == 0 || arr[i] != arr[i-1]+1)
			{
					current = 0;
			}
		current++;
		
		best = max(best, current);	
	}
		cout << best <<"\n";



}

}




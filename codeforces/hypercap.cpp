#include <bits/stdc++.h>

using namespace std;


int main(){


	int t;

	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<int> a(n);

		for(int &i : a) cin >> i;


		// logic saar
		// simple counting problem 
		// since you have grace swap , calculate how many adjacent ai, ai+1 elements are equal
		// and return cnt -1, basically an O(N) time complexity and O(1) space complexity considering no extra storage for the algo
		//


		int cnt = 0;

		for(int i = 1; i < n; i++){
			if(a[i] == a[i-1]) 
				cnt++;
		}


		cout << min(n, n - cnt +1) << '\n';
	}


}

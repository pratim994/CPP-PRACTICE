#include <bits/stdc++.h>


using namespace std;



int main(){

	int t;

	cin >> t;


	while(t--)
	{
		int n;
		cin >> n;
		vector<int> a(n) , b(n);
		for(int &i : a) cin >> i;
		for(int &i : b) cin >> i;
		int ans = 0;
		if(a == b){
			cout << 0 << '\n';
			continue;
		}
		for(int i = 0; i < n; i++)
		{
			if(a[i] != b[i]){
				
				ans += a[i];
				
		}

	}
		if(accumulate(a.begin(), a.end(), 0 ) == 0|| accumulate(b.begin(), b.end(),0) == n){
			cout << -1 << "\n" ;
			continue;
		}
		if(ans%2 == 1){
			cout << 1 << '\n';
		}
		else{

			cout << 2 << '\n';
		}
	}
return 0;

}







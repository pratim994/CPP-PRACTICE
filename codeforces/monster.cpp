#include <bits/stdc++.h>
using namespace std;

const int  N = 2e5+12;
int a[N], b[N];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		for(int i =1; i <= n; i++) cin >> a[i];
		for(int i = 1; i<= n; i++) cin >> b[i];
	
	int sum = 0 , h = 0;
	long long ans =0;
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);		
		for(int i = 1; i <= n; i++){
			
			while(h < n && sum + b[h+1] <= i) h++, sum += b[h];

			ans = max(ans, a[i]*1ll*h);
		}
		cout << ans << "\n";


}
}

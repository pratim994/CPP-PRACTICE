#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main()
{
    int t; cin >> t;
    
    while( t -- )
    {
    	int n, q; cin >> n >> q;
    	int a[n + 5], b[n + 5], pref[n + 5], ans = 0;
    	
    	for( int i = 1; i <= n; i ++ ) cin >> a[i];
    	for( int i = 1; i <= n; i ++ ) cin >> b[i];

	a[n + 1] = 0;

	for( int i = n; i > 0; i -- ) a[i] = max({a[i], a[i + 1], b[i]});
    	
    	pref[0] = 0;
    	for( int i = 1; i <= n; i ++ ) pref[i] = pref[i - 1] + a[i];
    	
    	for( int i = 1; i <= q; i ++ ){
    	    int L, R; cin >> L >> R;
    	    cout << pref[R] - pref[L - 1] << " ";
    	}
    	cout << "\n";
    }
}

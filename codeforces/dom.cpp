#include<bits/stdc++.h>
using namespace std;

#define sz(a) int((a).size())

int n;
vector<int> a;

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	return true;
}

inline void solve() {
	int ans = n + 5;
	vector<int> lst(n + 1, -1);
	for(int i = 0; i < n; i++) {
		if(lst[a[i]] != -1)
			ans = min(ans, i - lst[a[i]] + 1);
		lst[a[i]] = i;
	}
	if(ans > n)
		ans = -1;
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	while(tc--) {
		assert(read());
		solve();
	}
	return 0;
}

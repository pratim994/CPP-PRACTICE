#include <bits/stdc++.h>

using namespace std;

void solve()
{

	int n, m;

	long long ans = 0;

	cin >> n >> m;

	vector<long long> a(n), b(m);

	for(auto &x : a) cin >> x;

	for(auto &x : b) cin >>x;

	b.push_back(0);

	sort(b.begin(), b.end());

	vector<long long> prefix(n+1);
	for(long long i = 0; i < n; ++i){
		prefix[i+1] = prefix[i] +a[i];
	}

	for(long long i =1; i < b.size(); ++i){
		ans += abs(prefix[b[i]] - prefix[b[i-1]]);
		}

	ans += prefix[n] - prefix[b.back()];

	cout << ans << '\n';


}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}


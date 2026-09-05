#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
    }
    
    int m;
    cin >> m;
    vector<bool> has_dam(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int u;
        cin >> u;
        has_dam[u] = true;
    }
    
    vector<int> cameras;
    
    for (int i = n; i >= 2; --i) {
        if (has_dam[i]) {
            int parent = p[i];
            if (has_dam[parent]) {
                cameras.push_back(i);
            } else {
                has_dam[parent] = true;
            }
        }
    }
   sort(cameras.begin(), cameras.end()); 
    cout << cameras.size();
    for (int u : cameras) {
        cout << " " << u;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


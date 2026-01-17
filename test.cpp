#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        set<int> s;
        bool can = true;
        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (s.count(x)) {
                can = false;
            }
            s.insert(x);
        }
        
        cout << (can ? "YES" : "NO") << '\n';
    }
    
    return 0;
}

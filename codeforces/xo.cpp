#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int ans = 0;
        int cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        
        // Now handle wrap-around: continue counting from end to start
        for (int i = 0; i < n && s[i] == '0'; ++i) {
            cnt++;
        }
        ans = max(ans, cnt);
        
        cout << ans << '\n';
    }
}

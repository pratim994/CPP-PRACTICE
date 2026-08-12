#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> all_types(s.begin(), s.end());
    int total_unique = all_types.size();

    map<char, int> window_counts;
    int l = 0, r = 0;
    int ans = n;
    int current_unique = 0;

    while (r < n) {
        if (window_counts[s[r]] == 0) {
            current_unique++;
        }
        window_counts[s[r]]++;
        r++;

        while (current_unique == total_unique) {
            ans = min(ans, r - l);
            window_counts[s[l]]--;
            if (window_counts[s[l]] == 0) {
                current_unique--;
            }
            l++;
        }
    }

    cout << ans << "\n";
    return 0;
}


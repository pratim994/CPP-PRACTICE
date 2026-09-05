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

        vector<long long> a(n);
        int zeros = 0;

        for (auto &x : a) {
            cin >> x;
            if (x == 0)
                zeros++;
        }

        if (zeros == 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        string ans(n, 'C');

        if (zeros == 0) {
            cout << ans << '\n';
            continue;
        }
        int firstZero = -1;
        int secondZero = -1;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                if (firstZero == -1)
                    firstZero = i;
                else {
                    secondZero = i;
                    break;
                }
            }
        }

        ans[firstZero] = 'A';
        ans[secondZero] = 'B';

        for (int i = 0; i < n; ++i) {
            if (i == firstZero || i == secondZero)
                continue;

            if (a[i] == 2)
                ans[i] = 'A';
            else
                ans[i] = 'C';
        }

        cout << ans << '\n';
    }

    return 0;
}


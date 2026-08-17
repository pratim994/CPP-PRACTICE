#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    /*
        Let x and y be the heights of the mountains currently occupied
        by Bea and Ver.

        On Bea's turn:
          - she decreases Ver's mountain by 1
          - if Ver's current mountain becomes 0, she can only continue
            if Ver has another mountain to move onto.

        The same happens symmetrically for Ver.

        Because the arrays are non-increasing, a giant can move forward
        exactly when the next mountain is one higher than the current
        mountain.  We can process these transitions without simulating
        every single throw.
    */

    int i = 0, j = 0;
    ll x = a[0], y = b[0];

    // Bea starts.
    bool beaTurn = true;

    while (true) {
        if (beaTurn) {
            // Bea attacks Ver's current mountain.
            --y;

            if (y == 0) {
                // Ver has no usable mountain left.
                if (j + 1 == m) {
                    cout << 1 << '\n';
                    return;
                }

                // Ver jumps to the next mountain.
                ++j;
                y = b[j];
            }

            // If Bea can jump, do so.
            if (i + 1 < n && a[i + 1] == x + 1) {
                ++i;
                x = a[i];
            }

            beaTurn = false;
        } else {
            // Ver attacks Bea's current mountain.
            --x;

            if (x == 0) {
                if (i + 1 == n) {
                    cout << 2 << '\n';
                    return;
                }

                ++i;
                x = a[i];
            }

            if (j + 1 < m && b[j + 1] == y + 1) {
                ++j;
                y = b[j];
            }

            beaTurn = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

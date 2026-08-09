#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;

int64_t modpow(int64_t a, int64_t b) {
    int64_t ans = 1;

    while (b > 0) {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int64_t n, m, r, c;
        cin >> n >> m >> r >> c;

        int64_t constraints = (n - r + 1) * (m - c + 1);

        int64_t freeCells = n * m - constraints;

        cout << modpow(2, freeCells) << '\n';
    }
}

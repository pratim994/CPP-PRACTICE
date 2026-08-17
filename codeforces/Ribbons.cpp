#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int MAXN = 1'000'000;

ll fact[MAXN + 1], invFact[MAXN + 1];

ll modPow(ll a, ll e) {
    ll res = 1;

    while (e > 0) {
        if (e & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        e >>= 1;
    }

    return res;
}

ll C(int n, int k) {
    if (k < 0 || k > n)
        return 0;

    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

ll compositions(int total, int runs) {
    if (runs == 0)
        return (total == 0 ? 1 : 0);

    if (total < runs)
        return 0;

    return C(total - 1, runs - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[MAXN] = modPow(fact[MAXN], MOD - 2);

    for (int i = MAXN; i >= 1; i--) {
        invFact[i - 1] = invFact[i] * i % MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        int cnt0 = 0;
        int cnt1 = 0;
        int transitions = 0;

        for (char c : s) {
            if (c == '0')
                cnt0++;
            else
                cnt1++;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1])
                transitions++;
        }

        int runs0 =
            (transitions + (s[0] == '0') + (s[n - 1] == '0')) / 2;

        int runs1 =
            (transitions + (s[0] == '1') + (s[n - 1] == '1')) / 2;

        ll ways0 = compositions(cnt0, runs0);
        ll ways1 = compositions(cnt1, runs1);

        ll answer = ways0 * ways1 % MOD;

        cout << answer << '\n';
    }

    return 0;
}

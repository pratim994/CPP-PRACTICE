#include <bits/stdc++.h>

using namespace std;

template <typename T> inline bool umax(T &a, const T &b) { if(a < b) { a = b; return 1; } return 0; }

const long long inf = 4.1e18;
const int LG = 61;

long long get_different(long long power, long long k, long long A) {
    long long B = k - A;
    vector<vector<long long>> dp(2, vector<long long>(16, -inf));
    dp[0][0] = 0;

    int cnt_states = 0;
    for(int L = LG - 1; ~L; L--) {
        vector<vector<long long>> ndp(2, vector<long long>(16, -inf));

        for(int C = 0; C < 2; C++) {
            for(int cd = 0; cd < 4; cd++) {
                int a = A >> L & 1;
                int b = B >> L & 1;
                int c = cd >> 1;
                int d = cd & 1;

                int new_C = (k >> L & 1) ^ c ^ d;
                if((new_C + c + d >= 2) != C) continue;

                for(int mask = 0; mask < 16; mask++) {
                    if(dp[C][mask] < 0) continue;

                    // ac - 0, ad - 1, bc - 2, bd - 3
                    int new_mask = mask;
                    long long add = 0;

                    if((1ll << L) >= power && c) add += (2ll << L) - 2, new_mask |= (1 << 0) | (1 << 2);
                    if((1ll << L) >= power && d) add += (2ll << L) - 2, new_mask |= (1 << 1) | (1 << 3);

                    if((new_mask >> 0 & 1 ^ 1) && (a & c)) add += (1ll << L + 1) - 1, new_mask |= 1 << 0;
                    if((new_mask >> 1 & 1 ^ 1) && (a & d)) add += (1ll << L + 1) - 1, new_mask |= 1 << 1;
                    if((new_mask >> 2 & 1 ^ 1) && (b & c)) add += (1ll << L + 1) - 1, new_mask |= 1 << 2;
                    if((new_mask >> 3 & 1 ^ 1) && (b & d)) add += (1ll << L + 1) - 1, new_mask |= 1 << 3;

                    if(new_mask >> 0 & 1 ^ 1) add += ((long long) (a | c)) << L;
                    if(new_mask >> 1 & 1 ^ 1) add += ((long long) (a | d)) << L;
                    if(new_mask >> 2 & 1 ^ 1) add += ((long long) (b | c)) << L;
                    if(new_mask >> 3 & 1 ^ 1) add += ((long long) (b | d)) << L;

                    cnt_states++;
                    long long cand = dp[C][mask] + add;
                    umax(ndp[new_C][new_mask], cand);
                }
            }
        }

        dp = ndp;
    }

    long long best = -inf;
    for(int mask = 0; mask < 16; mask++) {
        umax(best, dp[0][mask]);
    }
    return best + 4;
}

long long get(long long x, long long k) {
    if(k == 1) return 1;

    int px = __lg(x ^ x + k - 1);
    long long Px = 1ll << px;
    x &= Px * 2 - 1;

    long long a = Px - 1 - x;
    return get_different(Px, k - 2, a);
}

void solve() {
    long long k, x;
    cin >> x >> k;

    cout << get(x, k) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ttt = 1;
    cin >> ttt;
    while(ttt--) {
        solve();
    }
}

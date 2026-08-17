#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

struct Segment {
    ll l, r;
    ll h;
};

static ll clampMul(ll a, ll b) {
    return (ll)((i128)a * b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll S;
        int q;
        cin >> S >> q;

        vector<ll> divs;

        for (ll d = 1; d * d <= S; ++d) {
            if (S % d == 0) {
                divs.push_back(d);
                if (d * d != S)
                    divs.push_back(S / d);
            }
        }

        sort(divs.begin(), divs.end());

        vector<Segment> seg;

        ll prev = 0;

        for (ll d : divs) {
            seg.push_back({prev + 1, d, S / d});
            prev = d;
        }

        int K = (int)seg.size();

        vector<ll> prefW(K + 1, 0);
        vector<ll> prefWH(K + 1, 0);

        for (int i = 0; i < K; ++i) {
            ll w = seg[i].r - seg[i].l + 1;

            prefW[i + 1] = prefW[i] + w;
            prefWH[i + 1] =
                (ll)((i128)prefWH[i] + (i128)w * seg[i].h);
        }

        auto fullContribution = [&](int k, ll y) -> ll {
            if (k == 0)
                return 0;

            int lo = 0, hi = k;

            while (lo < hi) {
                int mid = (lo + hi) / 2;

                if (seg[mid].h >= y)
                    lo = mid + 1;
                else
                    hi = mid;
            }

            int p = lo;

            i128 res = 0;

            res += (i128)prefW[p] * y;

            res += (i128)(prefWH[k] - prefWH[p]);

            return (ll)res;
        };

        while (q--) {
            ll x, y;
            cin >> x >> y;

            int lo = 0, hi = K - 1;

            while (lo < hi) {
                int mid = (lo + hi) / 2;

                if (seg[mid].r >= x)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            int pos = lo;

            i128 answer = fullContribution(pos, y);

            ll width = x - seg[pos].l + 1;
            ll height = min(y, seg[pos].h);

            answer += (i128)width * height;

            cout << (ll)answer << '\n';
        }
    }

    return 0;
}

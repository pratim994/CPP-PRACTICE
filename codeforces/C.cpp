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

        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        int bestL = -1, bestR = -1;
        int first = -1;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0)
                continue;

            if (first == -1)
                first = i;

            if (a[i] == 1) {
                if (bestL == -1 || i - first > bestR - bestL) {
                    bestL = first;
                    bestR = i;
                }

                first = i;
            }
        }
        if (first != -1) {
            int last = first;

            for (int i = first + 1; i < n; ++i) {
                if (a[i] != 0)
                    last = i;
            }

            if (bestL == -1 || last - first > bestR - bestL) {
                bestL = first;
                bestR = last;
            }
        }

        for (int &x : a)
            if (x == -1)
                x = 0;

        if (bestL != -1) {
            a[bestL] = 1;
            a[bestR] = 1;
        }

        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}

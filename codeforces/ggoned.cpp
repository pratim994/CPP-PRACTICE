#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> parent(n + 1, 0);
        vector<vector<int>> children(n + 1);

        for (int i = 2; i <= n; ++i) {
            cin >> parent[i];
            children[parent[i]].push_back(i);
        }

        int m;
        cin >> m;

        vector<bool> dam(n + 1, false);
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            dam[x] = true;
        }

        vector<bool> open(n + 1, false);

        vector<int> answer;
        for (int v = n; v >= 1; --v) {
            int keep = dam[v] ? 1 : 0;

            for (int u : children[v]) {
                if (!open[u])
                    continue;

                if (keep == 0) {
                    keep = 1;
                } else {
                    answer.push_back(u);
                }
            }

            open[v] = (keep != 0);
        }

        cout << answer.size();
        for (int u : answer)
            cout << ' ' << u;
        cout << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;


int main(){

    ios::sync_with_stdio(0);

    int t;

    cin >> t;

    while(t--) {

        int n , m;

        cin >> n >> m;

        vector<vector<int>> g(n);

        for(int i = 0; i < m ; i++) {

            int v,  u;

            cin >> v >> u;

            --v, --u;

            g[v].push_back(u);

            g[u].push_back(v);

        }

        vector<int> clr(n , -1);

        int ans = 0;

        for(int i = 0; i < n; i++)
        
        if(clr[i] == -1)
        {

            queue<int> q;

            q.push(i) ;

            clr[i] = 0;

            vector<int> cnt(2);

            bool ok = true;

            while(!q.empty()) {
                
                int v = q.front();

                q.pop();

                ++cnt[clr[v]];

                for(int u : g[v]) {

                    if (clr[u] == clr[v])

                        ok = false;

                    else if (clr[u] == -1){

                        clr[u] = clr[v] ^ 1;

                        q.push(u);

                    }

                }

            }
            if (ok) ans += max(cnt[0] , cnt[1]);
        }

        cout << ans << '\n';

    }

    return 0;
}
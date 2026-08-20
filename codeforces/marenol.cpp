#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int oddA = 0, oddB = 0;
        int evenA = 0, evenB = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == '1') {
                if (i % 2 == 0)
                    oddA++;
                else
                    evenA++;
            }

            if (b[i] == '1') {
                if (i % 2 == 0)
                    oddB++;
                else
                    evenB++;
            }
        }

        if (oddA == oddB && evenA == evenB)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

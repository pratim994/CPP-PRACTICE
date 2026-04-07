#include <bits/stdc++.h>
using namespace std;

int main() {
    int g, c, l;
    cin >> g >> c >> l;
    
    int mn = min({g, c, l});
    int mx = max({g, c, l});
    
    if (mx - mn >= 10) {
        cout << "check again\n";
    } else {
        // median = sum - min - max
        cout << "final " << (g + c + l - mn - mx) << '\n';
    }
    
    return 0;
}

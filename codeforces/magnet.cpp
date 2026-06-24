#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int groups = 1;
    string prev, current;
    
    cin >> prev;
    for (int i = 1; i < n; i++) {
        cin >> current;
        if (current != prev) {
            groups++;
        }
        prev = current;
    }

    cout << groups << "\n";
    return 0;
}


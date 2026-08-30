#include <bits/stdc++.h>

using namespace std;


int main(){

	int k;

	cin >> k;

	while(k--){
		
	 int n;
    cin >> n;
    long long total_sum = 0;
    map<int, int> freq;
    
    int max_f = 0;
    int maj_val = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        total_sum += x;
        freq[x]++;
        if (freq[x] > max_f) {
            max_f = freq[x];
            maj_val = x;
        }
    }
    
    int others = n - max_f;
    
    int max_majority_played = min(max_f, others + 2);
    
    long long ans = (total_sum - 1LL * max_f * maj_val) + 1LL * max_majority_played * maj_val;
    cout << ans << "\n";

	}

return 0;

}

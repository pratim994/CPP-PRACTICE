#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define all(vec) (vec).begin(), (vec).end()


#define rall(vec) (vec).rbegin(), (vec).rend()

template <class T> void readV(vector<T>& v) { for(auto &x :  v) std::cin >> x;}

template <class T> void printV(const vector<T>& v) { for(auto x : v) std::cout << x << ' '; std::cout << '\n';  }

string check_all_perms(string s , int idx) {

	std:sort(s.begin(), s.end());

	    idx--;

	    while(idx--)

		    next_permutation(s.begin(), s.end());

	    return s;
}

void solve () {

	std::string n;

	int j , k;

	std::cin >> n >> j >> k;

	std::string  a = check_all_perms(n, j);

	std::string b = check_all_perms(n, k);


	int A =0, ln = a.size();

	for(int i = 0; i < ln; i++)
		if(a[i] == b[i]) A++;

	int B = ln - A;
	std::cout << A << "A" << B << "B\n";
}

int32_t main() {

	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	int t = 1;

	if(!(std::cin >> t)) return 0;

	for(int tc = 1; tc <= t; tc++){

		solve();

	}

	return 0;
}



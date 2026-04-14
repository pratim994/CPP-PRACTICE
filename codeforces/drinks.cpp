#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

//solution for codeforces 200 B

int main()
{

	int n;

	std::cin >> n; 

	vector<int> arr(n);

	for(auto &i : arr) std::cin >> i ;

	int sum = std::accumulate(arr.begin(), arr.end(), 0);

	double t = (double)sum/n;

	cout << std::fixed << std::setprecision(12) << t << '\n';

}

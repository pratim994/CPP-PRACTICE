#include <bits/stdc++.h>

using namespace std;


int main()

{

	int t;

	cin >> t;

	while(t--)
	{

	int a, b, c;
	cin >> a >> b >> c;

		vector<int> arr= {a, b, c};

	sort(arr.begin() , arr.end());

	cout << min(arr[1], std::abs(arr[2] - arr[0])) << '\n';
	}

	return 0;

}

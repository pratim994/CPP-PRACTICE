#include <bits/stdc++.h>

using namespace std;

//solution for codeforces 467A
int main()
{

	int n = 0, p = 0 , q= 0 , cnt = 0;

	scanf("%d" , &n);

	while(n--)
	{

		std::cin >> p >> q;

		if(q - p >= 2)

			cnt++;

	}


	std::cout << cnt << '\n';

}


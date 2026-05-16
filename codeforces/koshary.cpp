#include<bits/stdc++.h>



int main()
{

	int t = 0;

	int x = 0, y =0;
	scanf("%d",&t );
			
	while(t--)
	{
		std::cin >> x >> y;
		std::cout << (x%2 == 0 || y%2 == 0 ? "YES" : "NO") << '\n';
	}
}


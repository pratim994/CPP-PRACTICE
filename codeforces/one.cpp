#include <bits/stdc++.h>
using namespace std;




int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		
		int minStr = 0, maxStr =0;

		for(auto& ch : s){
			if(ch == '1'){
				minStr++;
				maxStr++;
			}
		}

	//count ones in the string
	for(int i = 1; i <= n-1 ; i++)
	{
		if(s[i-1] == '1' && s[i+1] == '1')
		{
			if(s[i] == '0')
			{
			 maxStr++; 
			}
			if(s[i] == '1')
			{
				minStr--;
			}
		}
		if(maxStr > n) maxStr = n;
	}
	if(s[0] == '0') minStr -= 1;
	cout << minStr <<" " << maxStr << "\n";
	}
	return 0;

}	


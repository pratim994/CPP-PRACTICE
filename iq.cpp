#include <bits/stdc++.h>

using namespace std;

int main()
	{
		int n; 
		
		
		cin >> n;	
	
		int  a[101], lastOdd = 0 ,  lastEven = 0 , countE = 0 , countO = 0 ;
	
			
		for(int i = 0; i <n ; i++){	

			cin >> a[i];

			if(a[i]%2 == 0){
				
				countE++;

				lastEven = i+1;
			}
			else {
				countO++;
				
				lastOdd = i+1;
			}
		
		}

		if(countE > countO)
			cout << lastOdd << '\n';

		else 
			cout << lastEven << '\n';
	


	}
				

#include<bits/stdc++.h>

using namespace std;


int main()
{

	// seems like coin change problem from LC from first sight
	 

	int n;

	scanf("%d" , &n);

	// A damm good problem , exactly like coin change
	
	// Try with moduloing with the max number and if there is any remainder try with the second largest and so on and so forth 
	// so how do I create the sub problem , why not map  the elements to a hash map or pre fix array ex :
	//  arr[0,0,0,0,0] that maps for [1,5,10,20,100] so if money - 100 != 0 the arr[4]++; si
	//
	
	int mincur = 0;

	int ar[] = {1,5,10,20,100};
	

	for(int i = 4; i >= 0; i--){

		mincur += n/ar[i];

		n%=ar[i];

	}

	cout << mincur << '\n';

}

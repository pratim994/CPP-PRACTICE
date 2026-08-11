#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n; 

	scanf("%d", &n);

	vector<int> arr(n);
	int total = 0;
	for(int &i : arr ){ cin >> i; total += i; } 


	int ans  = 0;

	sort(arr.begin(), arr.end(), greater<int>());


	int count = 0, sum = 0;

	for(int i =0; i  <n; i++){


		sum += arr[i];
		count++;

		if(sum > total -sum){

			break;
		}


		}

		cout << count << "\n";	
	return 0;

}

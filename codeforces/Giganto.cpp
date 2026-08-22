#include <bits/stdc++.h>

using namespace std;


int main(){

	 int t;
	 cin >> t;

	 while(t--){
	
		 int n, m;

		 cin >> n >> m;


		 vector<int> a(n) , b(m);

		 int suma = 0, sumb =0;

		for(auto &i : a){ cin >> i;}

		for(auto &i : b){ cin >> i;}

	
		cout << ((a[0] + n >= b[0] + m) ? 1 : 2) << '\n';


 

			 }




		// very simple question I dont knwo why slop gpt pooped so hard on this one lol 
		// so my approach is first check if the lengths are equal and if the sum of the arrays are equal
		// if sum are equal then 1 wins else if sum is greater then 2 wins because 1 gets the first move



		
	 return 0;


}

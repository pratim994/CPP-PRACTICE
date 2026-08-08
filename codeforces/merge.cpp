#include <bits/stdc++.h>
#include <chrono>


using namespace std;


int main()
{


	int t;

	scanf("%d", &t);

	while(t--){

	int n, m;

	scanf("%d %d", &n, &m);

	vector<int> a(n), b(m);

	for(int &i : a){ cin >> i;}

	for(int &i : b){ cin >>i;}

	// now implemment the logic 
	// choose a number z form a such that x <= z <= y
	// delete x and y,  check wether a could be equal to 
	// b
	// if possible print YES or NO

	sort(begin(a), end(a));

	sort(b.begin(), b.end());

	if(n < 2*m){
		puts("NO");

		continue;
	}

	int i = 0;
	 while(i  <m && a[i] < b[i] && b[i] < a[n-m+i]) ++i;
	 	puts(i < m ? "NO" : "YES");
	}

	return 0;

}

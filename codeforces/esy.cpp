#include <bits/stdc++.h>


int main()
{
	int t, i;

	scanf("%d", &t); //you can use std::cin >> t; 
	
	bool flag = false;

	while(t--)
	{
		scanf("%d", &i); // cin >> i ;

		if(1&i == 1) flag = true;
	}


	if(flag){

		printf("HARD\n"); //std::cout << "HARD\n";
	}
	else{
		printf("EASY\n"); // std::cout << "EASY\n";
	}



}


/*codeforces 1030 

-> 800 rated 

-> easy problem

-> dont use an array to store the elements

-> input the stream and validate by negation 

->By default we assume the problem is easy and we let the input prove us otherwise 

->if flag is true we print "HARD" , for this problem specifically we don't have to follow the strict output format

-> but it's  still best practice*/

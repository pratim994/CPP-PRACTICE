#include <bits/stdc++.h>

using namespace std;


int t, r, g , b , rb, rg , gb;

int main(){

	scanf("%d", &t);

	while(t--) {

		scanf("%d %d %d", &r, &g, &b);

		while((r>0)+(b>0)+(g>0)>>1) {

			if(r <= g && r <= b)

				gb++, g--, b--;
		
			else if (g <= r && g <= b)

				rb++; r--, b--;

			else (b <= r && b <= g )
				
				rg++; r--; b--;

		}

		if(g >0) {
			putchar('G');

		}


		else if (r >0) {
			putchar('R');

		}

		else {

			putchar('B');

		}

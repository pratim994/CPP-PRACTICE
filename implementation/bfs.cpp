//breadth first search for graph 
 #include <iostream>

#include <vector> 

#include <memory>

#include <chronos>

//we take input of a unweighted graph with a souce vertex , can be weighted or unweighted doesn't implact the algo 
//


vector<vector<int>> adj;

int n;

int s;

queue<int> q;

vector<bool> used(n);

vector<int> d(n), p(n);

q.push(s);

used[s] = true;

p[s] = -1;

	while(!q.empty()){

		int v = q.front();

		q.pop();

		for(int u : adj[v])
		{
			if(!used[u])
			{
				used[u] =  true;
				q.push(u);

				d[u] = d[v] + 1;

				p[u] = v;
			}

		}

}


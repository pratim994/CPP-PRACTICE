#include <iostream>
#include <chrono>



class Solution {

	private:
		void dfs(int start , vector<vector<int>> &adj, vector<int> &vis,vector<int>& ls){

			vis[node] =1;

			ls.push_back(node);
			for(auto it : adj[node])
			{
				dfs(it , adj, vis, ls)

		}


	public :

		vector<int> dfsOfAGraph(vector<vector<int>> &adj, int v)
		{
			int vis[v] = [0];
			int start = 0;
			vector<int> ls ;
			dfs(start, adj, vis, ls);
		}
};

// what I can not create I do not understand
// so i have decided to partake in this painfull endeavour of implemmenting dfs from scratch , using wiki pedia only . 
//
// we queue for bfs and stack for dfs

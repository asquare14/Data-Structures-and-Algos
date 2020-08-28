// https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/
#include<bits/stdc++.h>
using namespace std;

vector<int> color;
int dfs_timer = 0;

void addEdge(int v, int w,vector<vector<int>> &adj)
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
bool dfs(int v, vector<vector<int>> &adj) {
    color[v] = 1;
    for (int u : adj[v])
    {
        if(color[u]==1)
            return true;
        if (color[u] == 0 && dfs(u,adj))
                return true;        
    }
    color[v] = 2;
    return false;
}
int main()
{
    int n = 4;
    vector<vector<int>> adj(n);
    addEdge(0, 1,adj); 
    addEdge(0, 2, adj); 
    addEdge(1, 2, adj); 
    addEdge(2, 0, adj); 
    addEdge(2, 3, adj); 
    addEdge(3, 3, adj); 
    color.resize(n);
    // for (int i = 0; i < V; i++) 
    //     if (color[i] == WHITE) 
    //        if (DFSUtil(i, color) == true) 
    //           return true; 
  
    // return false; 
    cout<<dfs(1,adj);
}
/**

Check if a vertex in a tree is an ancestor of some other vertex:
At the beginning and end of each search call we remember the entry and exit "time" of each vertex. 
Now you can find the answer for any pair of vertices (i,j) in O(1): 
vertex i is an ancestor of vertex j if and only if entry[i]<entry[j] and exit[i]>exit[j].

**/
#include<bits/stdc++.h>
using namespace std;

vector<int> color;
vector<int> time_in, time_out;
int dfs_timer = 0;

void addEdge(int v, int w,vector<vector<int>> &adj)
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 

/*
As described in the applications it might be useful to also compute the entry and exit times and vertex color. 
We will color all vertices with the color 0, if we haven't visited them, 
with the color 1 if we visited them, and 
with the color 2, if we already exited the vertex.
*/
void dfs(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}
int main()
{
    int n = 5;
    vector<vector<int>> adj(n);
    addEdge(0, 1,adj); 
    addEdge(1, 2,adj); 
    addEdge(3, 4,adj); 
    dfs(0);
}
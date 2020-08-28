#include<bits/stdc++.h>
using namespace std;
// Check if path exists from src to dest using BFS
void addEdge(vector<int> adj[],int v,int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
void bfs(vector<int> adj[],int s,int V)
{
    queue<int> q;
    vector<bool> used(V);
    q.push(s);
    while(!q.empty())
    {
        int node = q.top();
        q.pop();
        for(int i=0;i<adj[node].size();i++)
        {
            if(!used[adj[node][i]])
            {
                used[adj[node][i]] = true;
                q.push(used[adj[node][i]]);
            }
        }
    }


}

int main()
{
    int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, V); 
    bfs(adj,0,V);
    return 0;
}
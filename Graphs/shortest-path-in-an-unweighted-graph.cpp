#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int v,int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
void bfs(vector<int> adj[],int s,int dest, int V)
{
    queue<int> q;
    vector<bool> used(V);
    vector<int> d(V), p(V);
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    
    //Print Shortest Path
    if (!used[dest]) {
    cout << "No path!";
    } 
    else {
        vector<int> path;
        for (int v = dest; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
   

}

int main()
{
    int V = 8; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 3); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 3, 4); 
    addEdge(adj, 3, 7); 
    addEdge(adj, 4, 5); 
    addEdge(adj, 4, 6); 
    addEdge(adj, 4, 7); 
    addEdge(adj, 5, 6); 
    addEdge(adj, 6, 7); 
    bfs(adj,0,6,V);
    return 0;
}
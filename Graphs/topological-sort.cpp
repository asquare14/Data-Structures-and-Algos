// Only DAGs have a vlaid Topological Sort ordering
#include<bits/stdc++.h>
using namespace std;

bool visited[1000]={false};
stack<int> s;
void dfs(int v,vector<vector<int>> &adj)
{
    visited[v]=true;
    // cout<<v<<endl;
    for (size_t i = 0; i < (int) adj[v].size(); ++i)
        if(!visited[adj[v][i]])
            dfs(adj[v][i],adj);
    s.push(v);
}

void topologicalSort(vector<vector<int>> &adj,int V) {
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
            dfs(i,adj); 
  
    // Print contents of stack 
    while (s.empty() == false) 
    { 
        cout << s.top() << " "; 
        s.pop(); 
    } 

}
void addEdge(int v, int w,vector<vector<int>> &adj)
{ 
    adj[v].push_back(w); 
} 

int main()
{
    int n = 6;
    vector<vector<int>> adj(n);
    addEdge(5, 2, adj); 
    addEdge(5, 0, adj); 
    addEdge(4, 0, adj); 
    addEdge(4, 1, adj); 
    addEdge(2, 3, adj); 
    addEdge(3, 1, adj); 
    topologicalSort(adj,n);
}



#include<bits/stdc++.h>
using namespace std;

bool visited[1000]={false};
void dfs(int v,vector<vector<int>> &adj)
{
    visited[v]=true;
    //cout<<v<<endl;
    for (size_t i = 0; i < (int) adj[v].size(); ++i)
        if(!visited[adj[v][i]])
            dfs(adj[v][i],adj);
}

void addEdge(int v, int w,vector<vector<int>> &adj)
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 

int main()
{
    int n = 5;
    vector<vector<int>> adj(n);
    addEdge(0, 1,adj); 
    addEdge(1, 2,adj); 
    addEdge(3, 4,adj); 
    int c = 0;
    for (int i=0; i<n; i++) 
    { 
        if (!visited[i]) 
        {  
                dfs(i,adj); 
                c++;
        } 
     }
     cout<<"Connected Components is "<<c<<endl;
}
#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/discuss/interview-question/555856/Google-or-Onsite-or-Verify-if-N-ary-tree-is-ancestor-preserving-on-another-tree

bool visited[1000]={false};

bool bfs(vector<int> adj[],int V,int s,int dest)
{
    queue<int> q;
    vector<bool> used(V);
    q.push(s);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if(v==dest)
        {
            return true;
        }
        //cout<<v<<" ";
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
            }
        }
    }
    return false;
}


void addEdge(vector<int> adj[],int v,int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
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
    int src = 0;
    int dest = 3;
    cout<<bfs(adj,V,src,dest)<<endl;
}
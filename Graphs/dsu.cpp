// Find cycle in graph using DSU
// https://cp-algorithms.com/data_structures/disjoint_set_union.html
#include<bits/stdc++.h>
using namespace std;

int size[100000]={0};
int parent[100000]={-1};

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if(v==parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void addEdge(int v, int w,vector<vector<int>> &adj)
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 

int hasCycle(vector<vector<int>> &adj, int V) {
    for (int v = 0; v < V; ++v) 
        parent[v] = v;
    
    for(auto edge:adj)
    {
        int x = edge[0];
        int y = edge[1];
        if(x==y)
            return 1;
        union_sets(x,y);
    }

    return 0;
}
int main()
{
    int V;
    V=3;
    vector<vector<int>> adj(V);
    addEdge(2, 0,adj); 
    addEdge(1, 2,adj);
    addEdge(0, 2,adj);

    if(hasCycle(adj,V))
        cout<<"Has Cycle"<<endl;
    else cout<<"No Cycle"<<endl;



}
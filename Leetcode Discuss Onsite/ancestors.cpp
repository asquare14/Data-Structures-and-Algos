// Find all ancestors for each node in a DAG
#include<bits/stdc++.h>
using namespace std;

bool visited[1000]={false};
vector<char> st;
unordered_map<char,vector<char>> m;
void dfs(char v,vector<vector<char>> &adj)
{
    visited[v-'0']=true;
    cout<<v<<" ";
    vector<char> t(st.begin(),st.end());
    m[v] = t;
    st.push_back(v);

    for (size_t i = 0; i < (int) adj[v].size(); ++i)
    {
        if(!visited[adj[v][i]-'0'])
        {
           
            dfs(adj[v][i],adj);

        }
    }    
    st.pop_back();     
}

void addEdge(char v, char w,vector<vector<char>> &adj)
{ 
    adj[v].push_back(w); 
} 

int main()
{
    int n = 5;
    vector<vector<char>> adj(n);
    addEdge('A', 'D',adj); 
    addEdge('A', 'G',adj); 
    addEdge('G', 'F',adj); 
    addEdge('G', 'R',adj); 
    // Store in-degree = 0 nodes and do dfs from them
    dfs('A',adj);
    for(auto node:m)
    {
        cout<<node.first<<":";
        vector<char> c = node.second;
        for(auto e:c)
            cout<<e<<" ";
        cout<<endl;
    }
}
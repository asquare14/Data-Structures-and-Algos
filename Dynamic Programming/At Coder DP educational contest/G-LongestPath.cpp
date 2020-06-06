#include<bits/stdc++.h>
using namespace std;
bool visited[100000]={false};
void dfs(int v,vector<vector<int>> &adj,vector<int> &dp)
{
    visited[v]=true;
   // cout<<v<<endl;
    for (size_t i = 0; i < (int) adj[v].size(); ++i)
    {
        if(!visited[adj[v][i]])
            dfs(adj[v][i],adj,dp);
    
        dp[v] = max(dp[v], 1 + dp[adj[v][i]]); 
    }

}

int main()
{
    int N; int M;
    cin>>N>>M;
    vector<vector<int>> g(N+1);
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    vector<int> dp(N+1);
    for (int i = 1; i <= N; i++) { 
        if (!visited[i]) 
            dfs(i, g, dp); 
    } 
    int ans = 0; 
  
    // Traverse and find the maximum of all dp[i] 
    for (int i = 1; i <= N; i++) { 
        ans = max(ans, dp[i]); 
    } 
    cout<<ans<<endl;
    return 0; 
}
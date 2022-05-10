// We cannot find out using DSU as we won't be able to know which edge direction
set<int> visited, dfsVisited;
map<int,vector<int>> adj;

bool dfs(int src) {
    visited.insert(src);
    dfsVisited.insert(src);
    for(auto nb:adj[src]) {
        if(visited.count(nb)==false) {
            if(dfs(nb)) return true;
        } else if(dfsVisited.count(nb)) {
            return true;
        }
        
    }
    dfsVisited.erase(src);
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    visited.clear(); adj.clear(); dfsVisited.clear();
    for(auto edge:B) {
        adj[edge[0]].push_back(edge[1]);
    }
    for(int i=1;i<=A;i++)
        if(visited.count(i)==false && dfs(i)) return true;
    return false;
}

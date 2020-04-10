// https://www.youtube.com/watch?v=NR4fpjuxnPA
#include<bits/stdc++.h> 
using namespace std; 

//graph
unordered_map<int,vector<pair<int,int>>> m;

void addEdge(int u, int v, int dist, bool bi=true)
{
    m[u].push_back(make_pair(v,dist));
    if(bi)
        m[v].push_back(make_pair(u,dist));
}

void print()
{
    for(auto j:m){
        cout<<j.first<<"->";
        for(auto l: j.second){
            cout<<"("<<l.first<<","<<l.second<<")";    
        }
        cout<<endl;
    }
}

void dijisktra(int src)
{
    unordered_map<int,int> dist;
    for(auto j:m)
        dist[j.first] = INT_MAX;
    
    set<pair<int,int>> s;
    dist[src] = 0;
    s.insert(make_pair(0,src));
    
    while(!s.empty())
    {
        auto p = *(s.begin());
        int node = p.second;
            
        int nodeDist = p.first;
        s.erase(s.begin());

        for(auto childPair: m[node]){    
            if(nodeDist + childPair.second < dist[childPair.first]){
                int dest = childPair.first;
                auto f = s.find( make_pair(dist[dest],dest));
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[dest] = nodeDist + childPair.second;
                s.insert(make_pair(dist[dest],dest));    
            }    
        }
    }

    for(auto d:dist){
        cout<<d.first<<" is located at distance of  "<<d.second<<endl;
    }

}


int main() 
{ 
    addEdge(1,2,1);
    addEdge(1,3,4);
    addEdge(2,3,1);
    addEdge(3,4,2);
    addEdge(1,4,7);
    //print();
    dijisktra(1);

	return 0; 
} 

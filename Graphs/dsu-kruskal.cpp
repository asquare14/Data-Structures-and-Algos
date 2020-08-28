// https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html
#include<bits/stdc++.h>
using namespace std;

int size[100000]={0};
int parent[100000]={-1};
int count = 1;
int find_set(int v) {
    if(v==parent[v])
        return v;
        return parent[v]=find_set(parent[v]);
}

void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
}

static bool comp(const vector<int>& a, const vector<int>& b)         {
    return (a[2] < b[2]);
}

int minimumCost(int N, vector<vector<int>>& connections) {
    sort(connections.begin(), connections.end(), comp);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    int res = 0, count = 1;
    for (auto& c : connections) {
        int rx = find_set(c[0]), ry = find_set(c[1]);
        if (rx != ry) {
            res += c[2];
            union_sets(rx, ry);
            count++;
        }
        if (count == N) return res;
    }
    return -1;
}

int main()
{
    vector<vector<int>> c = {{1,2,5},{1,3,6},{2,3,1}};
    int N = 3;
    cout<<minimumCost(N,c);
}
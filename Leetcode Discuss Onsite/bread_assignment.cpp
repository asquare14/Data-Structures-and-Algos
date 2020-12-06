
// Some error is there debug
#include<bits/stdc++.h>
using namespace std;
int i = 0;
void assign(map<char,vector<char>> &m,char host, vector<char> &res,char parent)
{
  
    for(auto next:m[host])
    {
        if(next==parent)
            continue;
        assign(m,next,res,host);
    }
    res[i++] = host;
}
char solve(vector<vector<char>> &connections,char host, int k)
{
    int n = pow(2,k);
    vector<char> res(n);
    map<char,vector<char>> m;
    for(auto con:connections)
    {
        m[con[0]].push_back(con[1]);
        m[con[1]].push_back(con[0]);
    }
    assign(m,host,res,'0');
}
int main()
{
    vector<vector<char>> connections = {{'A','C'},{'C','B'},{'A','D'}};
	solve(connections, 2, 'A');
	// for(auto c : res) {
	// 		cout<<c+" ";
	// }
}
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<char> > &grid)
{
    queue<pair<int,int> > q;
    int r = grid.size();
    int c = grid[0].size();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]=='P')
            {
                q.push(make_pair(i,j));
            }
        }
    }
    int dirs[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int count = 1;
    int res = 0;
    while(!q.empty())
    {
        int sz = q.size();
        for(int i=0;i<sz;i++)
        {
            pair<int,int> p = q.front();
            q.pop();
            for(auto d:dirs)
            {
                int ni = p.first + d[0];
                int nj = p.second + d[1];
                if (ni >= 0 && ni <r && nj >= 0 && nj < c && grid[ni][nj] == '-')
                {
                    grid[ni][nj] = count + '0';
                    q.push(make_pair(ni,nj));
                    res = max(res,count);
                }
            }
 
        }
        count++;
    }
    return count;

}

int main()
{
    
    cout<<solve(grid);
}
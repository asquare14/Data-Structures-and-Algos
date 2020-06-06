#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int sum(long long int a,long long int b) 
{ 
    // add two numbers 
    long long int s = a + b; 
  
    // do a mod with m 
    s = s % mod; 
  
    return s; 
} 
int main()
{
    long long int r,c;
    cin>>r>>c;
    long long int grid[r][c];

    for(long long int i=0;i<r;i++)
    {
        for(long long int j=0;j<c;j++)
        {
            char c; cin>>c;
            if(c=='.')
                grid[i][j] = 0;
            else 
            {
                grid[i][j] = 1;
            }
        }
    }
    
    vector<vector<long long int> > dp(r + 1, vector<long long int> (c + 1, 0));
    dp[0][1] = 1;
        
    for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                if (grid[i - 1][j - 1]==0)
                    dp[i][j] = sum(dp[i - 1][j],dp[i][j - 1]);
        
    cout<<dp[r][c]<<endl;
    return 0;


}
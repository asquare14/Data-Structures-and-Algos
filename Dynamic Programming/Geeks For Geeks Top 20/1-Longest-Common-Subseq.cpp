#include<bits/stdc++.h>
using namespace std;
int lcs(string a, string b)
{
    int r = a.length(), c = b.length();
    int dp[r+1][c+1];
    for(int i=0;i<=r;i++)
        dp[i][0] = 0;

    for(int i=0;i<=c;i++)
        dp[0][i] = 0;

    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            
        }
    return dp[r][c];
}

int main()
{
    string a = "ABCDGH";
    string b = "AEDFHR";
    cout<<lcs(a,b)<<endl;
}
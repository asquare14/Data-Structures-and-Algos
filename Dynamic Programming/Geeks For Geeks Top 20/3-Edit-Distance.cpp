#include<bits/stdc++.h>
using namespace std;
int edit_distance(string a, string b)
{
    int r = a.length(), c = b.length();
    int dp[r+1][c+1];
    for(int i=0;i<=r;i++)
        dp[i][0] = 0;

    for(int i=0;i<=c;i++)
        dp[0][i] = 0;

    for(int i=0;i<=r;i++)
        for(int j=0;j<=c;j++)
        {
            int cost = 1;
            if(a[i-1] == b[j-1])
                cost = 0;
            else
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            
        }
    return dp[r][c];
}

int main()
{
    string a = "ABCDGH";
    string b = "AEDFHR";
    cout<<edit_distance<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    int dp[n+1][m+1]={0};
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if (i == 0 || j == 0)  
                dp[i][j] = 0; 
            else if(s[i-1]==t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
    }
    // cout<<"Length:"<<dp[n][m]<<endl;
   string ans;
   int i = n, j = m; 
   while (i > 0 && j > 0) 
   { 
      if (s[i-1] == t[j-1]) 
      { 
          ans += s[i-1];  
          i--; j--;      
      }  
      else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   // Print the lcs 
    reverse(ans.begin(), ans.end()); 
    cout<<ans;
    return 0;
}

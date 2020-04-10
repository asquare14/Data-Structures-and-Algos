#include<bits/stdc++.h>
using namespace std;
string scss(string a, string b)
{
    // LCS
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
    
   // Backtracking to find LCS string
   string ans;
   int i = r, j = c; 
   while (i > 0 && j > 0) 
   { 
      if (dp[i][j] == dp[i-1][j]) 
      { 
          ans+=a[i-1];
          i--;    
      } 
      else if (dp[i][j] == dp[i][j-1]) 
      {
          ans+=b[j-1];
          j--;
      } 
      else
      {
          ans+=a[i-1];
          i--;
          j--;
      } 
   }

   // Add remaining from a and b
    while(i-- > 0) {
        ans+=a[i];
    }
    while(j-- > 0) {
        ans+=b[j];
    }

    // Reverse string
    string t;
    for (int i=ans.length()-1; i>=0; i--) 
        t+=ans[i];  

   return t; 
}

int main()
{
    string a = "geek";
    string b = "eke";
    string ans = scss(a,b);
    cout<<ans<<endl;
}
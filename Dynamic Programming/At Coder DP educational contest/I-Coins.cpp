#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin>>N;
    double p[N+1];
    p[0] = 0.0;
    for(int i=1;i<=N;i++)
        cin>>p[i];
    double dp[N+1][N+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                dp[i][j] = dp[i-1][j] * (1-p[i]);
            else
            {
                  dp[i][j] = dp[i - 1][j]*(1.0 - p[i]) 
                           + dp[i - 1][j - 1] * p[i]; 
            }
            
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    double ans = 0.0; 
  
    for (int i = (N + 1) / 2; i <= N; i += 1) 
        ans += dp[N][i]; 
    printf("%0.10f", ans);  
    // cout<<ans<<endl;
    return 0;
  

}
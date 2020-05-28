#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,W;
    cin>>n>>W;
    long long int val[n+1];
    long long int wt[n+1];
    
    /* Space O(n*2)
    for(long long int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
	long long int i, w; 
	long long int dp[n + 1][W + 1]; 

	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) { 
			if (i == 0 || w == 0) 
				dp[i][w] = 0; 
			else if (wt[i - 1] <= w) 
				dp[i][w] = max( 
					val[i - 1] + dp[i - 1][w - wt[i - 1]], 
					dp[i - 1][w]); 
			else
				dp[i][w] = dp[i - 1][w]; 
		} 
	} 

	cout<<dp[n][W]<<endl;
    */

   /* Space O(n)*/
    long long int dp[W+1]={0};
    long long int ans = INT_MIN;
    for(long long int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }

    for(long long int i=0;i<n;i++)
        for(int j=W; j>=wt[i]; j--)
        {
            dp[j] = max(dp[j],val[i]+dp[j-wt[i]]);
        }
    
    for(long long int i=0;i<=W;i++)
        ans = max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
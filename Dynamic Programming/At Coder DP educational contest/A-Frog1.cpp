#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n; cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        arr.push_back(x);
    }
    int dp[n+1];
    dp[0]=0;
    dp[1]=abs(arr[0]-arr[1]);
    // cout<<dp[0]<<" "<<dp[1]<<" ";
    for(int i=2;i<n;i++)
    {
        int cost_1 = dp[i-1] + abs(arr[i]-arr[i-1]);
        int cost_2 = dp[i-2]+ abs(arr[i]-arr[i-2]);
        // cout<<min(cost_1,cost_2)<<" ";
        dp[i] = min(cost_1,cost_2);
    }

    cout<<dp[n-1]<<endl;

}
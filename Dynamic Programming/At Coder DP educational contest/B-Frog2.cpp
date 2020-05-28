#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main()
{
    long long int n; cin>>n;
    long long int k; cin>>k;
    vector<long long int> arr;
    for(int i=0;i<n;i++)
    {
        long long int x; cin>>x;
        arr.push_back(x);
    }
    vector<int> dp(n, INF);
    dp[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j <= i + k; ++j) {
            if(j < n) {
                int cost = dp[i] + abs(arr[i] - arr[j]);
                dp[j] = min(dp[j], cost);
            }
        }
    }

    cout<<dp[n-1]<<endl;
}
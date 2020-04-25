#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    int mx = amount + 1;
    int dp[amount + 1];
        
    for (int i = 0; i <= amount; i++)
        dp[i] = mx;
        
    dp[0] = 0;
        
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
        
    return dp[amount] > amount ? -1 : dp[amount];
        
}
int main()
{
    vector<int> coins;
    coins.pb(1);
    coins.pb(2);
    coins.pb(5);
    int amount = 11; 
    cout<<coinChange(coins,amount)<<endl;
}
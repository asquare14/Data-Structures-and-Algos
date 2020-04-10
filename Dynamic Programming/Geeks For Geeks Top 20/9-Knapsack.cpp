#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &val,vector<int> &weights,int W)
{
    int dp[val.size()+1][W+1];

    for(int i=0;i<=val.size();i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(weights[i-1]<=j)
                dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i-1][j-weights[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[val.size()][W];

}

int main()
{
    vector<int> values;
    values.push_back(60); 
    values.push_back(100);
    values.push_back(120);

    vector<int> weights;
    weights.push_back(10); 
    weights.push_back(20);
    weights.push_back(30);

    int  W = 50; 
    
    printf("%d", knapsack(values,weights,W)); 
    return 0; 
}
// https://www.youtube.com/watch?v=-GtpxG6l_Mc
#include<bits/stdc++.h>
using namespace std;
bool subset_sum(vector<int> &nums)
{
        int n = nums.size();
        int sum = 0; 
        for (int i = 0; i < nums.size(); i++) 
            sum += nums[i]; 
        if(sum%2==1)
            return false;
        sum=sum/2;
        vector<vector<int>> dp(n, vector<int>(sum+1));
    
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        for(int j=1;j<=sum;j++){
            if(nums[0]==j)
                dp[0][j]=true;
            else
                dp[0][j]=false;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                if(dp[i-1][j]){
                
                    dp[i][j] = dp[i-1][j];
                }else if(nums[i]<=j){
                    dp[i][j] = dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][sum];
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
   
    cout<<subset_sum(arr)<<endl;
}

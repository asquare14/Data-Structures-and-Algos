#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
        int r = 0;
        int sum = 0;
        map<int,int> m;
        m[0]++;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(m[sum-k])
                r +=m[sum-k];
            m[sum]++;
        }
        return r;
}
int subarraySumNoOverlap(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n+1];
        memset(dp,0,sizeof(0));
        int r = 0;
        int sum = 0;
        map<int,int> m;
        m[0]++;
        for(int i=1;i<=nums.size();i++)
        {
            dp[i] = dp[i-1];
            sum+=nums[i-1];
            if(m[sum-k])
                dp[i] =max(dp[i],dp[m[sum-k]]+1);
            m[sum]++;
        }
        return dp[n];
}
int main()
{
    vector<int> arr = { 1, 1, 1 };
    cout<<subarraySumNoOverlap(arr,2);
}
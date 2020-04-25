#include<bits/stdc++.h>
using namespace std;

int numRollsToTarget(int d, int f, int target) {
      vector<int> dp(target + 1);
      dp[0] = 1;
      for (int i = 1; i <= d; ++i) {
        vector<int> dp1(target + 1);
        for (int j = 1; j <= f; ++j)
          for (auto k = j; k <= target; ++k)
            dp1[k] = (dp1[k] + dp[k - j]) % 1000000007;
        swap(dp, dp1);
      }
      return dp[target];
}

int main()
{
    cout<<numRollsToTarget(1,6,3);
}
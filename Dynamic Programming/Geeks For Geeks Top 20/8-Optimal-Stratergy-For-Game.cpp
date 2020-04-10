// https://algorithms.tutorialhorizon.com/dynamic-programming-coin-in-a-line-game-problem/
#include<bits/stdc++.h>
using namespace std;
int optimal(vector<int> &arr)
{
    int n = arr.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    
    for (int interval = 0; interval <n; interval++) {
        for (int i = 0, j = interval; j < n; i++, j++) {
                // a = dp(i+2,j) - Alice chooses i Bob chooses i+1
                // b = dp(i+1,j-1)- Alice chooses i , Bob chooses j OR
                // Alice chooses j , Bob chooses i
                // c = dp(i,j-2)- Alice chooses j , Bob chooses j-1
            int a, b, c;
            if (i + 2 <= j)
                a = dp[i + 2][j];
            else
                a = 0;

            if (i + 1 <= j - 1)
                b = dp[i + 1][j - 1];
            else
                b = 0;

            if (i <= j - 2)
                c = dp[i][j-2];
            else
                c = 0;

            dp[i][j] = max(arr[i] + min(a, b), arr[j]+ min(b, c));
            }
        }
        return dp[0][n - 1];
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
   
    cout<<optimal(arr)<<endl;
    
}
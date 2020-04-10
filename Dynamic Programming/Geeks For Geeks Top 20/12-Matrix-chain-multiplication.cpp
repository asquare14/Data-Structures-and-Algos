#include<bits/stdc++.h>
using namespace std;
int matrix_chain(int m[],int n)
{
    int dp[n+1][n+1];
    int q = 0;

    for(int i=0;i<n;i++)
        dp[i][i] = 0;

     for (int L = 2; L < n; L++) 
    { 
        for (int i = 1; i < n - L + 1; i++) 
        { 
            int j = i + L - 1; 
            dp[i][j] = INT_MAX; 
            for (int k = i; k <= j - 1; k++) 
            { 
                q = dp[i][k] + dp[k + 1][j] +  
                    m[i - 1] * m[k] * m[j]; 
                if (q < dp[i][j]) 
                    dp[i][j] = q; 
            } 
        } 
    } 
  
    return dp[1][n - 1]; 
    
}
int main()
{
    int arr[] = {1, 2, 3, 4}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         <<  matrix_chain(arr, size); 

}
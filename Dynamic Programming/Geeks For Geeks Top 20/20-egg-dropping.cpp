// https://leetcode.com/problems/super-egg-drop/discuss/158974/C%2B%2BJavaPython-2D-and-1D-DP-O(KlogN)
// For time, O(NK) decalre the space, O(KlogN) running,
#include<bits/stdc++.h>
using namespace std;

int eggDrop(int N, int K) 
{       
        int dp[N+1][K+1] = {0};
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
} 

int main() 
{ 
	int n = 2, k = 36; 
	cout<<eggDrop(k,n); 
	return 0; 
} 

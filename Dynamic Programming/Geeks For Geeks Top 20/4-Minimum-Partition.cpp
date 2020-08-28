#include<bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=-GtpxG6l_Mc
int partition(vector<int> &arr)
{
    int n = arr.size();
	int sum = 0; 
	for (int i = 0; i < n; i++) 
		sum += arr[i]; 

	int dp[n+1][sum+1]; 

    for (int i=0; i<=n; i++) 
		for (int j=0; j<=sum; j++) 
            dp[i][j] = 0;

	for (int i = 0; i <= n; i++) 
		dp[i][0] = true; 

	for (int i = 1; i <= sum; i++) 
		dp[0][i] = false; 

	for (int i=1; i<=n; i++) 
	{ 
		for (int j=0; j<=sum; j++) 
		{ 
	    	if (arr[i-1] <= j) 
				dp[i][j] = (dp[i - 1][j] || dp[i-1][j-arr[i-1]]); 
            else dp[i][j] = dp[i-1][j];
		} 
	} 
   
	int diff = INT_MAX; 
	for (int j=sum/2; j>=0; j--) 
	{ 
		if (dp[n][j] == true) 
		{ 
			diff = sum-2*j; 
			break; 
		} 
	} 
	return diff; 
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    cout<<partition(arr)<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int dp[1000000][3];

int main(){
    int n; cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
	dp[1][1] =a; dp[1][2] = b;dp[1][3] = c;
	for(int i=2;i<=n;i++){
		cin>>a>>b>>c;
		dp[i][1] += a+max(dp[i-1][2],dp[i-1][3]);
		dp[i][2] += b+max(dp[i-1][1],dp[i-1][3]);
		dp[i][3] += c+max(dp[i-1][1],dp[i-1][2]);
	}
	cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int dp[1000000][3];

// int main(){
//     int n; cin>>n;
//     int a,b,c;
//     cin>>a>>b>>c;
// 	dp[1][1] =a; dp[1][2] = b;dp[1][3] = c;
// 	for(int i=2;i<=n;i++){
// 		cin>>a>>b>>c;
// 		dp[i][1] += a+max(dp[i-1][2],dp[i-1][3]);
// 		dp[i][2] += b+max(dp[i-1][1],dp[i-1][3]);
// 		dp[i][3] += c+max(dp[i-1][1],dp[i-1][2]);
// 	}
// 	cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
// 	return 0;
// }

#include<bits/stdc++.h>
 
using namespace std;
 
int dp[100005][4];
 
int solve(int day /*day*/,int prev_day_activity/* activity */, vector<vector<int>> &score) {
    
    int n = score.size();
    if(day>=n) {
        return 0;
    }
    
    if(dp[day][prev_day_activity+1]!=-1)
        return dp[day][prev_day_activity+1];
    
    int maxi = 0;
    
    if(prev_day_activity==-1) {
        maxi = max(maxi,score[day][0]+solve(day+1,0,score));
        maxi = max(maxi,score[day][1]+solve(day+1,1,score));
        maxi = max(maxi,score[day][2]+solve(day+1,2,score));
    } else if(prev_day_activity==0) {
        maxi = max(maxi,score[day][1]+solve(day+1,1,score));
        maxi = max(maxi,score[day][2]+solve(day+1,2,score));
    } 
    else if(prev_day_activity==1) {
        maxi = max(maxi,score[day][0]+solve(day+1,0,score));
        maxi = max(maxi,score[day][2]+solve(day+1,2,score));
        
    } else if(prev_day_activity==2) {
        maxi = max(maxi,score[day][0]+solve(day+1,0,score));
        maxi = max(maxi,score[day][1]+solve(day+1,1,score));
    }
    
    
    return dp[day][prev_day_activity+1]=maxi;
}
 
int main() {
  
  memset(dp, -1, sizeof dp);
  int N; cin>>N;
  
  vector<vector<int>> score;
  for(int i=0;i<N;i++) 
  {
    vector<int> v;
    for(int j=0;j<3;j++) {
        int x; cin>>x;
      	v.push_back(x);
    }
    score.push_back(v);
  }
  
  cout<<solve(0,-1,score);
  
  return 0;
 
}

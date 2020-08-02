#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int& x : a) {
        cin>>x;
    }
    vector<bool> dp(k + 1);
    for(int stones = 0; stones <= k; ++stones) {
        for(int x : a) {
            if(stones >= x && !dp[stones-x]) {
                dp[stones] = true;
            }
        }
    }
    if(dp[k])
        cout<<"First";
    else cout<<"Second";
    return 0;
}

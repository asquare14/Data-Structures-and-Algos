// https://leetcode.com/discuss/interview-question/528584/Google-or-Onsite-or-How-Far-Can-We-Reach-using-Rope-and-Bricks
#include <bits/stdc++.h>
using namespace std;
bool valid(const vector <int> &heights, int bricks, int ropes, int mid) {
    vector <int> jumps;
    for (int i = 1; i <= mid; ++i) {
        if (heights[i] > heights[i - 1]) {
            jumps.push_back(heights[i] - heights[i - 1]);
        }
    }
    
    sort(jumps.begin(), jumps.end());
    
    int i = 0;
    while (i < jumps.size() && bricks >= jumps[i]) {
        bricks -= jumps[i];
        ++i;
    }
    
    return ropes >= jumps.size() - i;
}

int solve(const vector <int> &heights, int bricks, int ropes) {
    int left = 0, right = heights.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        
        if (valid(heights, bricks, ropes, mid)) left = mid;
        else right = mid - 1;
    }
    
    return left;
}
int main()
{
    vector<int> arr;
    arr = {4,2,7,6,9,11,14,12,8};
    cout<<solve(arr,5,2);
    cout<<endl;
    cout<<solve(arr,5,1);
}
#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {       
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
}

int main()
{
    string s = "leetcode"; 
    vector<string> wordDict = {"leet", "code"};
    cout<<wordBreak(s,wordDict)<<endl;
}
class Solution {
public:
    bool wordBreak(string s,unordered_set<string> &set,vector<int> &dp,int start)
    {
        if(s.size()==start)
            return true;
        
        if(dp[start]!=-1)
            return dp[start];
        
        for(int i=start;i<s.size();i++)
        {
            if(set.count(s.substr(start,i+1-start)) && wordBreak(s,set,dp,i+1)){
                dp[start] = true;
                return true;
            }
        }

        return dp[start]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return wordBreak(s,set,dp,0);
    }
};
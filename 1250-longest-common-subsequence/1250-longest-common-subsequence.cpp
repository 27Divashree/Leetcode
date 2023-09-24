class Solution {
public:
    int solve(string s, string t)
    {
        vector<int> currRow(t.length()+1,0);//dp[i]
        vector<int> nextRow(t.length()+1,0);//dp[i+1]
        
        for(int i=s.length()-1;i>=0;i--)
        {
            for(int j=t.length()-1;j>=0;j--)
            {
                int ans = 0;
                if(s[i]==t[j])
                ans = 1 + nextRow[j+1];
            else
                ans = max(nextRow[j],currRow[j+1]);
                currRow[j] = ans;
            }
            nextRow = currRow;
        }
        
        return nextRow[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        //vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1)) ;
        return solve(text1,text2);
    }
};
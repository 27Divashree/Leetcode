class Solution {
public:
int solveTab(string a, string b)
{
    vector<int> curr(b.length()+1,0);   //dp[i+1]
    vector<int> next(b.length()+1,0);   //dp[i]

    for(int i=a.length()-1;i>=0;i--)
    {
        for(int j=b.length()-1;j>=0;j--)
        {
            int ans = 0;
            if(a[i]==b[j])
            {
                ans = 1 + next[j+1];
            }
            else
            {
                ans = max(curr[j+1],next[j]);
            }

            curr[j] = ans;
        }
        next = curr;
    }

    return next[0];
}
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int ans = solveTab(s,s2);
        return ans;
    }
};
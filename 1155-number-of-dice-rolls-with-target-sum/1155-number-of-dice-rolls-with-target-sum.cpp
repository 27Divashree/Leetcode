class Solution {
public:
    int numRollsToTarget(int n, int k, int sum) {
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++)
        {
            for(int q = 1; q <= sum; q++)
            {
                dp[i-1][q] += dp[i-1][q-1];
                dp[i-1][q]%=1000000007;
            }

            for(int j = 1; j <= sum; j++)
            {
                dp[i][j] = dp[i-1][j-1];
                if(j-k-1 >= 0)
                {
                    dp[i][j] -= dp[i-1][j-k-1];
                }
                dp[i][j] = (dp[i][j]+ 1000000007)%1000000007;
            }
        }

        return dp[n][sum];
    }
};

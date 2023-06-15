class Solution {
public:
    int solveTab(vector<int>& days, vector<int>& cost)
    {
        int n = days.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;

        for(int k= n-1;k>=0;k--)
        {
            //1 day pass
            int option1 = cost[0] + dp[k+1];

            //7 days pass
            int i;
            for(i=k; i<n && days[i]<days[k]+7; i++);
            int option2 = cost[1] + dp[i];

            //30 days pass
            for(i=k; i<n && days[i]<days[k]+30; i++);
            int option3 = cost[2] + dp[i];
            
            dp[k] = min(option1, min(option2, option3));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solveTab(days,costs);
    }
};
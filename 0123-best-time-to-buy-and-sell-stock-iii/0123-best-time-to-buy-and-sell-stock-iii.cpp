class Solution {
public:
    int solveRec(int index,int buy, vector<int>& prices,int limit)
    {
        if(index==prices.size())
            return 0;
        if(limit==0)
            return 0;
        
        int profit = 0;
        if(buy)
        {
            int doBuy = -prices[index] + solveRec(index+1,0,prices,limit);
            int skip = 0 + solveRec(index+1,1,prices,limit);
            profit = max(doBuy,skip);
        }
        else
        {
            int doSell = prices[index] + solveRec(index+1,1,prices,limit-1);
            int skip = 0 + solveRec(index+1,0,prices,limit);
            profit = max(doSell,skip);
        }
        return profit;
    }

    int solveMem(int index,int buy, vector<int>& prices,int limit,vector<vector<vector<int>>>& dp)
    {
        if(index==prices.size())
            return 0;
        if(limit==0)
            return 0;
        if(dp[index][buy][limit]!=-1)
            return dp[index][buy][limit];
        
        int profit = 0;
        if(buy)
        {
            int doBuy = -prices[index] + solveMem(index+1,0,prices,limit,dp);
            int skip = 0 + solveMem(index+1,1,prices,limit,dp);
            profit = max(doBuy,skip);
        }
        else
        {
            int doSell = prices[index] + solveMem(index+1,1,prices,limit-1,dp);
            int skip = 0 + solveMem(index+1,0,prices,limit,dp);
            profit = max(doSell,skip);
        }
        return dp[index][buy][limit]= profit;
    }

    int maxProfit(vector<int>& prices) {
        //return solveRec(0,1,prices,2);
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solveMem(0,1,prices,2,dp);
    }
};
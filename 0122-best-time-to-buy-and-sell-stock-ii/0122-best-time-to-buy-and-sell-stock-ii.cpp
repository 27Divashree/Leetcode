class Solution {
public:
    int solveTab(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit = 0;
                if(buy)
                {
                    int doBuy = -prices[index] + next[0];
                    int skip = 0 + next[1];
                    profit = max(doBuy,skip);
                }
                else
                {
                    int doSell = prices[index] + next[1];
                    int skip = 0 + next[0];
                    profit = max(doSell,skip);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};
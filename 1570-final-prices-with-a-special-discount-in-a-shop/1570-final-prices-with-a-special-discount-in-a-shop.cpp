class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
				int mini = INT_MAX;
				for(int i=0;i<prices.size()-1;i++)
				{
					mini = 0;
					for(int j=i+1;j<prices.size();j++)
					{
							if(prices[j]<=prices[i]){
								mini = prices[j];
								break;
							}
					}
					ans.push_back(prices[i]-mini);
				}

				ans.push_back(prices[prices.size()-1]);

				return ans;
    }
};
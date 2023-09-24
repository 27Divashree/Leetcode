class Solution {
public:
    int solve(int n,vector<int>& a)
    {
        vector<int> currRow(n+1,0);//dp[curr]
        vector<int> nextRow(n+1,0);//dp[curr+1]
        
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev = curr-1;prev>=-1;prev--)
            {
                //include
                int incl = 0;
                
                if(prev==-1 || a[curr]>a[prev])
                    incl = 1 + nextRow[curr+1];
                
                int excl = 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(incl,excl);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums.size(),nums);
    }
};
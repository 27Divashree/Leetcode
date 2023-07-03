class Solution {
public:
    bool solveRec(int index,vector<int>& nums,int target)
    {
        int n = nums.size();

        if(index>=n)
            return 0;
        if(target<0)
            return 0;
        if(target==0)
            return 1;

        bool incl = solveRec(index+1,nums,target-nums[index]);
        bool excl = solveRec(index+1,nums,target-0);

        return incl or excl;
    }

    bool solveMem(int index,vector<int>& nums,int n,int target,vector<vector<int>>& dp)
    {
        if(index>=n)
            return 0;
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        if(dp[index][target]!=-1)
            return dp[index][target];

        bool incl = solveMem(index+1,nums,n,target-nums[index],dp);
        bool excl = solveMem(index+1,nums,n,target-0,dp);

        return dp[index][target] = incl or excl;
    }

    bool solveTab(int N,vector<int>& nums,int total)
    {
        vector<vector<int>> dp(N+1,vector<int>(total+1,0));

        for(int i=0;i<=N;i++)
            dp[i][0] = 1;
        
        for(int index = N-1;index>=0;index--)
        {
            for(int target=0;target<=total/2;target++)
            {
                bool incl = 0;
                if(target-nums[index]>=0)
                    incl = dp[index+1][target-nums[index]];
                bool excl = dp[index+1][target-0];

                dp[index][target] = incl or excl;
            }
        }

        return dp[0][total/2];
    }

    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int total = 0;
        for(int i=0;i<nums.size();i++)
            total+=nums[i];
        if(total&1)
            return 0;
        int target = total/2;
        //return solveRec(0,nums,target);
        //vector<vector<int>> dp(N, vector<int>(target+1,-1));
        //return solveMem(0,nums,N,target,dp);
        return solveTab(N,nums,total);
    }
};
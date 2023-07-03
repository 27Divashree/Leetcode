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

    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int total = 0;
        for(int i=0;i<nums.size();i++)
            total+=nums[i];
        if(total&1)
            return 0;
        int target = total/2;
        //return solveRec(0,nums,target);
        vector<vector<int>> dp(N, vector<int>(target+1,-1));
        return solveMem(0,nums,N,target,dp);
    }
};
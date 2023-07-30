class Solution {
public:
    int findRec(int k,int n)
    {
        if(n==0 || n==1)
            return n;
        if(k==1)
            return n;
        int ans = 1000000;
        for(int i=1;i<=n;i++)
        {
            int temp = 1 + max(findRec(k-1,i-1), findRec(k,n-i));
            ans = min(ans,temp);
        }

        return ans;
    }

    int solveMem(int k,int n,vector<vector<int>> &dp)
    {
        if(n==0 || n==1)
            return n;
        if(k==1)
            return n;
        if(dp[k][n]!=-1)
            return dp[k][n];

        int ans = 1000000, l=1,h=n,temp=0;
        
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            int left = solveMem(k-1,mid-1,dp);
            int right = solveMem(k,n-mid,dp);
            temp = 1 + max(left,right);
            if(left<right)
                l = mid + 1;
            else
                h = mid - 1;
            ans = min(ans,temp);
        }

        return dp[k][n]=ans;
    }

    int solveTab(int k,int n)
    {
        if(n==0 || n==1)
            return n;
        if(k==1)
            return n;

        vector<vector<int>> dp(k+1, vector<int>(n+1,0));
        for(int i=0;i<=k;i++)
            dp[i][0] = 0, dp[i][1] = 1;
        for(int i=0;i<=n;i++)
        dp[0][i] = 0, dp[1][i] =i;

        for(int i=2;i<k+1;i++)
        {
            for(int j=2;j<n+1;j++)
            {
                int ans = 1000000, l=1,h=j,temp=0;
                while(l<=h)
                {
                    int mid = l + (h-l)/2;
                    int left = dp[i-1][mid-1];
                    int right = dp[i][j-mid];
                    temp = 1 + max(left,right);
                    if(left<right)
                        l = mid + 1;
                    else
                        h = mid - 1;
                    ans = min(ans,temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[k][n];
    }

    int superEggDrop(int k, int n) {
        //return findRec(k,n);
        vector<vector<int>> dp(k+1, vector<int>(n+1,-1));
        //return solveMem(k,n,dp);
        return solveTab(k,n);
    }
};
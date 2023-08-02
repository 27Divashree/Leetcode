class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int>& nums,int index)
    {
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int j=index;j<nums.size();j++)
        {
            swap(nums[j],nums[index]);
            solve(ans,nums,index+1);
            swap(nums[j],nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans,nums,0);
        return ans;
    }
};
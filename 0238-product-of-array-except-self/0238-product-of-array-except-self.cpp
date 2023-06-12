class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(size(nums),1);
        int begin = 1;
        int last =1;
        for(int i=0;i<nums.size();i++)
        {
            ans[i] *= begin;
            begin *= nums[i];
        }

        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i] *= last;
            last *= nums[i];
        }

        return ans;
    }
};
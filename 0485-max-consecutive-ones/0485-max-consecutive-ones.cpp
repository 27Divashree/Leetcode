class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, count = 0, maxi = 0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                count++;
                if(count>maxi)
                    maxi = count;
            }
            else
                count = 0;
        }
        return maxi;
    }
};
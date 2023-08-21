class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(count<k)
            {
                if(nums[i]<=0){
                    nums[i]*=-1;
                    count++;
                }
            }
        }
        sort(nums.begin(),nums.end());
        if(count!=k)
        {
            int temp = k-count;
            if(temp%2!=0)
                nums[0]*=-1;
        }
        int sums=0;
        for(int i=0;i<nums.size();i++)  
            sums+=nums[i];
        
        return sums;
    }
};
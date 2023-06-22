class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int window_sum = 0;
        int n = nums.size();
        int window_start=0, window_end=0;
        int min_length = INT_MAX;
        while(window_end < n){
            window_sum += nums[window_end];
            if(window_sum < target){
                window_end++;
            }
            else if(window_sum >= target){
                while(window_sum >= target){
                    min_length = min(min_length, window_end - window_start + 1);
                    window_sum = window_sum - nums[window_start];
                    window_start++;
                }
                window_end++;
            }
        }
        if(min_length == INT_MAX){
            return 0;
        }
        return min_length;
    }
};
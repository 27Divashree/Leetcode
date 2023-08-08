class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(k==0)
            return ans;
        
        deque<int> dq;
        for(int i=0,n=(int)nums.size();i<n;i++)
        {
            while(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            
            dq.push_back(i);

            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        

        return ans;
    }
};
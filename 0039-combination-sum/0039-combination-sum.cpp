class Solution {
public:
    void search(vector<int>& nums, int next, vector<int> sol, int target, vector<vector<int>> &result)
    {
        if(target==0)
        {
            result.push_back(sol);
            return;
        }

        if(next==nums.size() || target-nums[next]<0)
            return;
        
        sol.push_back(nums[next]);
        search(nums, next, sol, target-nums[next], result);
        sol.pop_back();
        search(nums, next+1, sol, target,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> sol;
        search(candidates,0,sol,target,result);
        return result;
    }
};
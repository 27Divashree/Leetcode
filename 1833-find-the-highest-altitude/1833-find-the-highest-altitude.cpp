class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=gain.size();i++)
        {
            ans.push_back(ans[i-1]+gain[i-1]);
        }

        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};
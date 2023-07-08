class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int> last(n+1,0);
        vector<int> curr(n+1,0);

        for(int i=n-1;i>=0;i--)
        {
            for(int prev = i-1;prev>=-1;prev--){
                int take = INT_MIN;
                if(prev==-1 ||  pairs[prev][1]<pairs[i][0])
                    take = 1 + last[i+1];
                int notTake = last[prev+1];
                curr[prev+1] = max(take,notTake);
            }
            last = curr;
        }

        return last[0];
    }
};
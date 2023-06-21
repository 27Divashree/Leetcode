class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        vector<int> v;

        for(int i=0;i<n;i++)
            arr[arr[i]%n] += n;
        
        for(int i=0;i<n;i++)
        {
            if((arr[i]/n)>1)
                v.push_back(i);
        }

        return v[0];
    }
};
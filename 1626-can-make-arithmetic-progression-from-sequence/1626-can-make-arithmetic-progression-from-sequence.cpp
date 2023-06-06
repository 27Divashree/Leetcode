class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return true;
        
        // Sort array
        sort(arr.begin(), arr.end());
        
        // After sorting, difference between
        // consecutive elements must be same.
        int d = arr[1] - arr[0];
        for (int i=2; i<n; i++)
            if (arr[i] - arr[i-1] != d)
            return false;
        
        return true;
    }
};
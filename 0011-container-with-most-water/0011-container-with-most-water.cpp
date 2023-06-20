class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxArea = 0;

        while(left<right)
        {
            int h = min(height[left],height[right]);
            maxArea = max(maxArea, (right-left)*h);

            while(height[left]<=h && left<right)
                left++;
            
            while(height[right]<=h && left<right)
                right--;   
        }

        return maxArea;
    }
};
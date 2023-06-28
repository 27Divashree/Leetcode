class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0,right=height.size()-1,level=0, waterHolds = 0;

        while(left<right)
        {
            while(left<right && height[left]<=level)
                waterHolds += level - height[left++];
            
            while(left<right && height[right]<=level)
                waterHolds += level - height[right--];

            level = min(height[left],height[right]);
        } 

        return waterHolds;
    }
};
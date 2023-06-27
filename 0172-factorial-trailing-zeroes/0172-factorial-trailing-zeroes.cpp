class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        for(int i=n;i>4;i=i/5)
        {
            cnt+=(i/5);
        }

        return cnt;
    }
};
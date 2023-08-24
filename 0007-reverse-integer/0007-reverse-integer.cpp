class Solution {
public:
    int reverse(int y) {
        long x = y;
        if(x>(pow(2,31)-1) || x<(-pow(2,31)))
            return 0;
        vector<long> res;
        long ans = 0;
        bool neg=false;
        if(x<0)
        {
            neg = true;
            x = x*(-1);
        }
        while(x>=1)
        {
            long temp = x%10;
            res.push_back(temp);
            x=x/10;
        }

        std::reverse(res.begin(),res.end());

        for(int i=0;i<res.size();i++)
        {
            ans = ans + res[i]*pow(10,i);
        }

        if(ans>(pow(2,31)-1) || ans<(-pow(2,31)))
            return 0;
        if(!neg)
            return ans;
        else
            return ans*(-1);
    }
};
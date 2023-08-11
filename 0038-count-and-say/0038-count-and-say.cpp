class Solution {
public:
    string helper(int n,string ans)
    {
        if(n==0)
            return ans;
        
        int i=0, j=0;
        string newAns= "";
        while(i<ans.length())
        {
            while(ans[i]==ans[j] && i<ans.length())
                i++;
            newAns += i-j+'0';
            newAns += ans[j];
            j=i;
        }
        return helper(n-1,newAns);
    }
    string countAndSay(int n) {
        string ans = "1";
        return helper(n-1,ans);
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        int n = s.length();

        for(int i=0;i<n;i++)
        {
            char c = s[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
                ans += tolower(c);
        }

        string dup = ans;
        reverse(dup.begin(),dup.end());
        if(ans==dup)
            return true;
        return false;
    }
};
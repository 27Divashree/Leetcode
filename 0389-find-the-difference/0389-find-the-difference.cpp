class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.size();i++)
            t[i+1] += t[i]-s[i];
        return t[t.size()-1];
    }
};
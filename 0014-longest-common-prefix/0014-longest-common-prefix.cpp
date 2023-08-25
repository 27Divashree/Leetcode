class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string a = strs[0];
        string b = strs[strs.size()-1];

        string s = "";
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==b[i])
                s.push_back(a[i]);
            else
                break;
        }

        return s;
    }
};
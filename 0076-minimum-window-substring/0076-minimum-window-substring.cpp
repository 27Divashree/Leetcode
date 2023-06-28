class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        if(s.empty() || t.empty())
            return ans;
        
        unordered_map<char,int> map;
        unordered_map<char,int> window;

        for(int i=0;i<t.length();i++)
            map[t[i]]++;
        
        int minLength  = INT_MAX, count = 0;
        for(int l=0,r=0;r<s.length();r++)
        {
            char c = s[r];
            if(map.find(c)!=map.end())
            {
                window[c]++;
                if(window[c]<=map[c])
                    count++;
            }

            if(count>=t.length())
            {
                while(map.find(s[l])==map.end() || window[s[l]]>map[s[l]])
                {
                    window[s[l]]--;
                    l++;
                }
                if(r-l+1 < minLength)
                {
                    minLength = r-l+1;
                    ans = s.substr(l,minLength);
                }
            }
        }

        return ans;
    }
};
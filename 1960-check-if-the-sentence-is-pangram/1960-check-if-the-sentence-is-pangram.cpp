class Solution {
public:
    bool checkIfPangram(string s) {
        sort(s.begin(), s.end());
        map<char, int> mp;
        for(auto i : s)
        {
            mp[i]++;
        }
        return mp.size()==26;
    }
};
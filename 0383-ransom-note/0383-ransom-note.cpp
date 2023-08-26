class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp1;
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        for(int i=0;i<ransomNote.length();i++)
        {
            mp1[ransomNote[i]]++;
        }

        unordered_map<char,int> mp2;
        for(int i=0;i<magazine.length();i++)
        {
            mp2[magazine[i]]++;
        }

        for(auto& c:mp1)
        {
            if (mp2.find(c.first) == mp2.end() || mp2[c.first] < c.second) 
                return false;
        }

        return true;
    }
};
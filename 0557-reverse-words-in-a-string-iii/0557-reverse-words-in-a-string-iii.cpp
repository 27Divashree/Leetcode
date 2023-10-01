class Solution {
public:
    string reverseWords(string s) {
        s = s + " ";
        int n = s.length();
        int i=0;
        for(int j=0; j<n; j++){
            if(s[j]==' '){
                reverse(s.begin()+i, s.begin()+j);
                i = j+1;
            }
        }
        s.pop_back();
        return s;
    }
};
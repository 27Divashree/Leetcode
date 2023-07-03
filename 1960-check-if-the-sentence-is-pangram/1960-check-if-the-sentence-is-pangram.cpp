class Solution {
public:
    bool checkIfPangram(string sentence) {
        return size(unordered_set<char>{begin(sentence), end(sentence)}) == 26;
    }
};
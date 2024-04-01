class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        while(s[s.size()-1-i] == ' '){
            i++;
        }
        int j = i;
        while(i < s.size() && s[s.size()-1-i] != ' '){
            i++;
        }
        return i-j;
    }
};
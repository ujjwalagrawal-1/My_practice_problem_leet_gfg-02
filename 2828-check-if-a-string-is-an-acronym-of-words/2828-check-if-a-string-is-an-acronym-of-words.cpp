class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int i = 0,j = 0;
        if(words.size() != s.size())return 0;
        while(i<s.size()){
            if(words[j][0] == s[i]){
                i++;j++;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};
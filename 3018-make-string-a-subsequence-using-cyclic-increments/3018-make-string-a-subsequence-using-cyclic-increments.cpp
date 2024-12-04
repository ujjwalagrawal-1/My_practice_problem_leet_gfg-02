class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while(i < str1.size() && j < str2.size()){
            if(str1[i] == str2[j]){
                i++;j++;
                continue;
            }
            char pc = str2[j] == 'a' ? 'z' : str2[j] - 1;
            if(str1[i] == pc){
                i++;j++;
            }
            else if(str1[i] != pc){
                i++;
            }
        }
        if(j == str2.size()){
            return true;
        }
        return false;
    }
};
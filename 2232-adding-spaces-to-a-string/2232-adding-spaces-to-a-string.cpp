class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        int j = 0;
        string temp = "";
        while(i<s.size()){
            if(j<spaces.size() && spaces[j] == i){
                temp += " ";
                j++;
            }
            temp += s[i];
            i++;
        }
        return temp;
    }
};
class Solution {
public:
    string compressedString(string word) {
        string ans ="";
        int maxicnt = 0;
        int i = 0;
        while(i<word.size()){
            char ch = word[i];
            while(i<word.size() && maxicnt+1 <= 9 && ch == word[i]){
                i++;
                maxicnt++;
            }
            ans += to_string(maxicnt);
            maxicnt = 0;
            ans += ch;
        }

        return ans;
    }
};
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find(ch);
        int j = 0;
        while(j<=i){
            swap(word[j],word[i]);
            j++;i--;
        }
        return word;
    }
};
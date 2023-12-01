class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";
        for(auto itr:word1){
            a += itr;
        }
        for(auto itr:word2){
            b += itr;
        }
        return a == b? 1:0;
    }
};
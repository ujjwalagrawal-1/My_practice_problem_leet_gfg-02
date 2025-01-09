class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int i = 0;
        for(auto& itr : words){
            if(itr.find(pref) == 0){
                i++;
            }
        }

        return i;
    }
};
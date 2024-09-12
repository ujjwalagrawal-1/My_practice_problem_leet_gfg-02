class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int i = 0;
        int cnt = 0;
        vector<int> freq(26,0);
        for(int i = 0;i<allowed.size();i++){
            freq[allowed[i] - 'a']  = 1;
        }
        for(int i = 0;i<words.size();i++){
            bool f = 1;
            for(int j = 0;j<words[i].size();j++){
                if(!freq[words[i][j] - 'a']){
                    f = 0;
                    break;
                }
            }
            if(f){
                cnt++;
            }
        }

        return cnt;
    }
};
class Solution {
public:
bool c(vector<int>& a){
    for(int i = 0;i<26;i++){
        if(a[i] != 0){
            return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int i = 0;
        vector<int> freq(26,0);
        for(int i = 0;i<s1.size();i++){
            freq[s1[i] - 'a']++;
        }
        int j = 0;
        while(j < s2.size()){
            freq[s2[j] - 'a']--;
            if(freq[s2[j] - 'a'] == 0 && i <= j && c(freq)){
                return true;
            }
            if(freq[s2[j] - 'a'] < 0){
                while(i <= j && freq[s2[j] - 'a'] < 0){
                    freq[s2[i] - 'a']++;
                    i++;
                }
            }
            j++;
        }
        return false;
    }
};
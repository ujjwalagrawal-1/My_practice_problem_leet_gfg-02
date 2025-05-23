class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int maxi = 0;
        int i = 0;
        int j = 0;
        while(j < s.size()){
            if(freq[s[j]] == 0){
                freq[s[j]]++;
            } else {
                while(freq[s[j]] != 0){
                    freq[s[i]]--;
                    i++;
                }
                freq[s[j]]++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};

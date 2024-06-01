class Solution {
public:
    int scoreOfString(string s) {
        int ans =0;
        int i = 1;
        while(i<s.size()){
            ans += abs(s[i] - s[i-1]);i++;
        }
        return ans;
    }
};
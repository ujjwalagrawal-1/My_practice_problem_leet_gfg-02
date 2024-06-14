#define M 1000000007;
class Solution {
public:
    int solve(string &str, int idx,vector<int> &dp) {
        if(idx == str.length()) return 1;
        if(dp[idx] != -1){
            return dp[idx];
        }
        int maxKeyPress = (str[idx] == '7' || str[idx] == '9') ? 4 : 3;
        long long currIndex = idx, pressFrequency = 1, ans = 0;
        while(pressFrequency <= maxKeyPress && str[currIndex] == str[idx]) {
            ++currIndex;
            ++pressFrequency;
            ans += solve(str, currIndex,dp) % M;
        }
        return dp[idx] = ans%M;
    }
    int countTexts(string pressedKeys) {
        vector<int> dp(pressedKeys.size()+1,-1);
        return solve(pressedKeys, 0,dp) % M;
    }
};
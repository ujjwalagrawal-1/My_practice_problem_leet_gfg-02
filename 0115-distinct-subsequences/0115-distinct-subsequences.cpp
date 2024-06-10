class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned int> dp(m + 1), temp(m + 1);

        dp[0] = temp[0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i - 1] == t[j - 1]) temp[j] = dp[j - 1] + dp[j];
                else temp[j] = dp[j];
            }
            dp = temp;
        }
        return dp[m];
    }
};
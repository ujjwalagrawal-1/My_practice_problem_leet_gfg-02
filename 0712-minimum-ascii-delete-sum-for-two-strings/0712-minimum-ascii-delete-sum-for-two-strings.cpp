class Solution {
public:
    int f(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) {
            return 0;
        }
        if (i < 0) {
            int sum = 0;
            for (int k = 0; k <= j; k++) {
                sum += (int)s2[k];
            }
            return sum;
        }
        if (j < 0) {
            int sum = 0;
            for (int k = 0; k <= i; k++) {
                sum += (int)s1[k];
            }
            return sum;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            dp[i][j] = f(s1, s2, i-1, j-1, dp);
        } else {
            dp[i][j] = min(f(s1, s2, i-1, j, dp) + (int)s1[i], f(s1, s2, i, j-1, dp) + (int)s2[j]);
        }
        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(s1, s2, m-1, n-1, dp);
    }
};

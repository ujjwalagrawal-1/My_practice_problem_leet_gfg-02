class Solution {
public:
    int f(vector<vector<int>>& pairs, int prev, int i, vector<vector<int>>& dp) {
        if (i >= pairs.size()) {
            return 0;
        }
        int dpIndex = (prev == -1001) ? 0 : prev + 1001;
        if (dp[i][dpIndex] != -1) {
            return dp[i][dpIndex];
        }
        int tk = 0, nt = 0;
        if (prev < pairs[i][0]) {
            tk = f(pairs, pairs[i][1], i + 1, dp) + 1;
        }
        nt = f(pairs, prev, i + 1, dp);
        dp[i][dpIndex] = max(tk, nt);
        return dp[i][dpIndex];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(pairs.size(), vector<int>(2002, -1));
        return f(pairs, -1001, 0, dp);
    }
};

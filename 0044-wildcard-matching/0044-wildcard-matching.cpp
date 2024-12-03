class Solution {
public:
    int dp[2005][2005];
    int fn(string& s, string& p, int i, int j) {
        if (i == s.size() && j == p.size())
            return 1;
        if (j == p.size())
            return 0;
        if (i == s.size()) {
            for (int k = j; k < p.size(); k++)
                if (p[k] != '*')return 0;
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if ((p[j] == '?' || s[i] == p[j]))
            ans |= fn(s, p, i + 1, j + 1);
        else if (p[j] == '*') {
            ans |= fn(s, p, i, j + 1);
            ans |= fn(s, p, i + 1, j);
        } else
            return 0;

        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return fn(s, p, 0, 0);
    }
};
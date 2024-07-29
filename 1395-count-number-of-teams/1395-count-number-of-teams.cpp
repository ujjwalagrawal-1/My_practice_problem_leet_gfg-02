class Solution {
public:
    int f(vector<int> &r, int i, int k, int prev, vector<vector<vector<int>>> &dp) {
        if (k == 0) {
            return 1;
        }
        if (i == r.size()) {
            return 0;
        }
        if (dp[i][k][prev + 1] != -1) {
            return dp[i][k][prev + 1];
        }
        int a = f(r, i + 1, k, prev, dp); 
        if (prev == -1 || r[prev] < r[i]) {
            a += f(r, i + 1, k - 1, i, dp);
        }
        return dp[i][k][prev + 1] = a;
    }
    
    int fr(vector<int> &r, int i, int k, int prev, vector<vector<vector<int>>> &dpp) {
        if (k == 0) {
            return 1;
        }
        if (i == r.size()) {
            return 0;
        }
        if (dpp[i][k][prev + 1] != -1) {
            return dpp[i][k][prev + 1];
        }
        int a = fr(r, i + 1, k, prev, dpp);
        if (prev == -1 || r[prev] > r[i]) {
            a += fr(r, i + 1, k - 1, i, dpp);
        }
        return dpp[i][k][prev + 1] = a;
    }
    
    int numTeams(vector<int>& r) {
        vector<vector<vector<int>>> dp(r.size(), vector<vector<int>>(4, vector<int>(r.size() + 1, -1)));
        vector<vector<vector<int>>> dpp(r.size(), vector<vector<int>>(4, vector<int>(r.size() + 1, -1)));
        return f(r, 0, 3, -1, dp) + fr(r, 0, 3, -1, dpp);
    }
};

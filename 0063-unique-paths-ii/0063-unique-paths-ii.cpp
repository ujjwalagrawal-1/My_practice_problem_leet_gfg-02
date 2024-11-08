#define M 2000000000

class Solution {
public:
    int f(vector<vector<int>>& g, int i, int j,vector<vector<int>> &dp) {
        if (i < 0 || j < 0)
            return 0;
        if (g[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int a = f(g, i - 1, j,dp);
        int b = f(g, i, j - 1,dp);
        return dp[i][j] =  (a + b) % M;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(g, n - 1, m - 1,dp);
        int dp[n][m];
        // using Tabulation
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if (g[i][j] == 1)dp[i][j] = 0;
                else if (i == 0 && j == 0)dp[i][j] = 1;
                else {int a = 0,b = 0;
                if(i-1 >=0)
                a = dp[i - 1][j];
                if(j-1 >=0)
                b = dp[i][j - 1];
                dp[i][j] = (a + b)%M;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

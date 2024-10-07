class Solution {
public:
    int f(vector<vector<char>>& matrix, int i, int j,vector<vector<int>> &dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (i >= n || j >= m || matrix[i][j] == '0') {
            return 0;
        }
        if(dp[i][j] !=  -1){
            return dp[i][j];
        }
        int right = f(matrix, i, j+1,dp);
        int down = f(matrix, i+1, j,dp);
        int diag = f(matrix, i+1, j+1,dp);
        return dp[i][j] = min({right, down, diag}) + 1;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    ans = max(ans, f(matrix, i, j,dp));
                }
            }
        }
        return ans * ans;
    }
};

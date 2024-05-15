class Solution {
public:
int f(vector<vector<int>> &triangle,int i,int j,vector<vector<int>> &dp){
    if(i == triangle.size()){
        return 0;
    }
    if(j >= i+1){
        return INT_MAX;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] =  min(f(triangle,i+1,j,dp),f(triangle,i+1,j+1,dp)) + triangle[i][j];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        return f(triangle,i,j,dp);
    }
};
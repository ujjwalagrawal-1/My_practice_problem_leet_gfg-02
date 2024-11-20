class Solution {
public:
int f(vector<int>& values,int i,int n,vector<vector<int>> &dp){
    if(i == n){
        return 0;
    }
    if(dp[i][n] != -1){
        return dp[i][n];
    }
    long long mini = INT_MAX;
    for(int k = i;k<=n-1;k++){
        mini = min(mini,f(values,i,k,dp) + f(values,k+1,n,dp) + 1ll*values[i-1]*values[k]*values[n]);
    }

    return dp[i][n] = mini;
}
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        return f(values,1,values.size()-1,dp);
    }
};
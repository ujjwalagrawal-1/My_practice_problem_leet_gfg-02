class Solution {
public:
int f(int n,int e,vector<vector<int>> &dp){
    if(n <= 1 || e == 1){
        return n;
    }
    if(dp[n][e] != -1){
        return dp[n][e];
    }
    int mini = INT_MAX;

    for(int i = 1;i<=n;i++){
        int ans = 1 + max(f(i-1,e-1,dp),f(n-i,e,dp));
        mini = min(mini,ans);
    }
    return dp[n][e] = mini;
}
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return f(n,2,dp);
    }
};
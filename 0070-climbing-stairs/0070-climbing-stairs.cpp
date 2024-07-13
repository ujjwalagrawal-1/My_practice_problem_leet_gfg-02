class Solution {
public:
int stairs(int n,vector<int> &dp){
    if(n==0)return 1;
    if(n==1)return 1;
    if(dp[n+2] != -1)return dp[n+2];
        return dp[n+2] =  stairs(n-1,dp) + stairs(n-2,dp);
}
    int climbStairs(int n) {
        vector<int> dp(n+3,-1);
        return stairs(n,dp);
    }
};
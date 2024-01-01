class Solution {
public:
int ans(int n){
        // vector<int> dp(n+1,0);
        // dp[0] = 1;
        // dp[1] = 1;
        int prev2 = 1;
        int prev1 = 1;
        for(int i = 2;i<=n;i++){
            int ans = prev2 + prev1;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
}
    int climbStairs(int n) {
    //    vector<int> dp(n+1,-1);
    //    return ans(n,dp);
        return ans(n);
    }
};
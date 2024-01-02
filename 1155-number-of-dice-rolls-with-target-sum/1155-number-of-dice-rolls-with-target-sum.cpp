class Solution {
public:
int mod = 1000000007;
int recursiverelation(int n,int k,int target){
    if( n<0){
        return 0;
    }
    if(n == 0 && target == 0){
        return 1;
    }
    if(n == 0 && target != 0){
        return 0;
    }
    int ans = 0;
    for(int i = 1;i<=k;i++){
        ans += recursiverelation(n-1,k,target-i);
    }
    return ans;
}
int memoisation(int n,int k,int target,vector<vector<int>> &dp){
    if(target <0 || n < 0){
        return 0;
    }
    if(n == 0 && target == 0){
        return 1;
    }
    if(n == 0 && target != 0){
        return 0;
    }
    if(dp[n][target] != -1){
        return dp[n][target]%mod;
    }

    int ans = 0;
    for(int i = 1;i<=k;i++){
        int recans = 0;
        if(target-i>=0)
        recans += memoisation(n-1,k,target-i,dp)%mod;
        ans = (ans + recans)%mod;
    }
    dp[n][target] = ans;
    return dp[n][target]%mod;
}
    int numRollsToTarget(int n, int k, int target) {
        // if(target < 0){
        //     return 0;
        // }

        // return recursiverelation(n,k,target);
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return memoisation(n,k,target,dp);
    }
};
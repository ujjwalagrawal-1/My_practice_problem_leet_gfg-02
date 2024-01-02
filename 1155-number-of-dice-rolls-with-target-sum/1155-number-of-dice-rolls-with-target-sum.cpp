class Solution {
public:
int mod = 1000000007;
int recursiverelation(int n,int k,int target){
    
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
    if(n == 0 && target == 0){
        return 1;
    }
    if(n == 0 && target != 0){
        return 0;
    }
    if(dp[n][target] != -1){
        return dp[n][target];
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
int tabulation(int n,int k,int target){
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[0][0] = 1;

    for(int N = 1;N<=n;N++){
        for(int j = 1;j<=target;j++){
            int ans = 0;
            for(int i = 1;i<=k;i++){
                int recans = 0;
                if(j-i>=0)
                recans += dp[N-1][j-i]%mod;
                ans = (ans + recans)%mod;
            }
            dp[N][j] = ans;
        }
    }
    return dp[n][target];
}
    int numRollsToTarget(int n, int k, int target) {
        // if(target < 0){
        //     return 0;
        // }
        // return recursiverelation(n,k,target);


        // // Memoisation concept
        // vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        // return memoisation(n,k,target,dp);


        ////////////
        return tabulation(n,k,target);
    }
};
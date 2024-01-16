class Solution {
public:
int solve_using_recursion(int n){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }

    int ans = INT_MAX;
    for(int i = 1;i<= sqrt(n);i++){
        int a = i*i;
        ans = min(ans,solve_using_recursion(n-a)+1);
    }

    return ans;
}
int solve_using_memoisation(int n,vector<int> &dp){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 10e8;
    for(int i = 1;i<=sqrt(n);i++){
        int a = i*i;
        ans = min(solve_using_memoisation(n-a,dp)+1,ans);
    }

    return dp[n] = ans;
}

int solve_using_tabulation(int n){
    vector<int> dp(n+1,0);
    dp[0] = 0;

    for(int j = 1;j<=n;j++){
        int ans = INT_MAX;
        for(int i = 1;i<=sqrt(j);i++){
        int a = i*i;
        ans = min (dp[j-a]+1,ans);
        }
        dp[j] = ans;
    }
    return dp[n];
}
    int numSquares(int n) {

        // solved using recursion
        // return solve_using_recursion(n) - 1;

        // solved using memoisation
        // vector<int> dp(n+1,-1);
        // return solve_using_memoisation(n,dp)-1;

        // solve using tabultion
        return solve_using_tabulation(n);
    }
};
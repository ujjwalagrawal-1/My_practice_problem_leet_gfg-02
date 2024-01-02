class Solution {
public:

int Memoisation(int n,vector<int>& dp){
        if(n == 0){
        return 0;
        }
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = Memoisation(n-1,dp) + Memoisation(n-2,dp) + Memoisation(n-3,dp);

        return dp[n];
}

int tb(int n){
    if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int j = 3;j<=n;j++){
         dp[j] = dp[j-1]+ dp[j-2] + dp[j-3];
    }
    return dp[n];
}
int sop(int n){
    int prev3 = 0;
    int prev2 = 1;
    int prev1 = 1;
    for(int j = 3;j<=n;j++){
        int curr = prev3 + prev2 + prev1;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
    int tribonacci(int n) {
        /*
        if(n == 0){
        return 0;
        }
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 1;
        }
        */
        // return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        // above one is the basic approch
        //////////////////////////////////


        // by Memoisation  method
        // vector<int> dp(n+1,-1);
        // return Memoisation(n,dp);
        ////////////////////////////////////


        // By Tabulation method
        // return tb(n);
        ///////////////////////


        // by Space Optimisation
        if(n == 0){
            return 0;
        }
        return sop(n);

    }
};
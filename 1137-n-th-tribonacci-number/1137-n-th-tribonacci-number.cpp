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
    int tribonacci(int n) {
        // if(n == 0){
        // return 0;
        // }
        // if(n == 1){
        //     return 1;
        // }
        // if(n == 2){
        //     return 1;
        // }

        // return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);


        // above one is the basic approch
        vector<int> dp(n+1,-1);
        return Memoisation(n,dp);
    }
};
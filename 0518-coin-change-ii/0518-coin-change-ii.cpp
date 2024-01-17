class Solution {
public:
    int solve(int amount,vector<int>& coins,int i){
        if(i == 0){
            return (amount%coins[0] == 0);
        }


        int b = solve(amount,coins,i-1);
        int a = 0;
        if(amount >= coins[i])
        a = solve(amount-coins[i],coins,i);
        
        return a + b;
    }
    int solve_using_Memoisation(int amount,vector<int>& coins,int i,vector<vector<int>>& dp){
        if(i == 0){
            return (amount%coins[0] == 0);
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int a = 0;
        if(amount >= coins[i])
        a = solve_using_Memoisation(amount-coins[i],coins,i,dp);
        int b = solve_using_Memoisation(amount,coins,i-1,dp);

        return dp[i][amount] = a + b;
    }
    int solve_using_tabulation(int amount, vector<int>& coins, int i, vector<vector<int>>& dp) {
        for (int ind = 0; ind <= amount; ind++) {
            dp[0][ind] = (ind % coins[0] == 0);
        }
        for (int ind = 1; ind < i; ind++) {
            for (int amo = 0; amo <= amount; amo++) {
                int a = 0;
                if (amo >= coins[ind])
                    a = dp[ind][amo - coins[ind]];
                int b = dp[ind - 1][amo];
                dp[ind][amo] = a + b;
            }
        }
        return dp[i - 1][amount];
    }
    int change(int amount, vector<int>& coins) {
        int index = coins.size();
        // return solve(amount,coins,index);

        vector<vector<int>> dp(index,vector<int> (amount+1,0));
        // return solve_using_Memoisation(amount,coins,index,dp);

        return solve_using_tabulation(amount,coins,index,dp);
    }
};
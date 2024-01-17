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
    int solve_using_tabulation(int amount,vector<int>& coins,vector<vector<int>>& dp){
        for(int i = 0;i<dp[0].size();i++){
            dp[0][i] = (amount%coins[0] == 0);
        }
        for(int it = 1;it<coins.size();it++){
            for(int h = 0;h <= amount;h++){
            int a = 0;
            if(h >= coins[it])
            a = dp[it][h-coins[it]];
            int b = dp[it-1][h];
            dp[it][h] = a + b;
            }
        }
        return dp[coins.size()-1][amount];
    }
    int change(int amount, vector<int>& coins) {
        int index = coins.size()-1;
        // return solve(amount,coins,index);

        vector<vector<int>> dp(index+1,vector<int> (amount+1,-1));
        // return solve_using_Memoisation(amount,coins,index,dp);

        return solve_using_tabulation(amount,coins,dp);
    }
};
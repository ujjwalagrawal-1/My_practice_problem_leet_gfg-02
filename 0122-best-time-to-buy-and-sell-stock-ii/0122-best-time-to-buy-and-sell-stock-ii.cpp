class Solution {
public:

// This give TLE
int solve_using_recursion(vector<int>& prices,int ind,bool buy){
    if(ind >= prices.size()){
        return 0;
    }
    int profit = 0;
    if(buy){
        profit = max(-prices[ind] + solve_using_recursion(prices,ind+1,0),0 + solve_using_recursion(prices,ind+1,1));
    }
    else{
        profit = max(prices[ind] + solve_using_recursion(prices,ind+1,1),0 + solve_using_recursion(prices,ind+1,0));
    }
    return profit;
}

int solve_using_memoisation(vector<int>& prices,int ind,bool buy,vector<vector<int>>& dp){
    if(ind >= prices.size()){
        return 0;
    }
    if(dp[ind][buy] != -1){
        return dp[ind][buy];
    }
    int profit = 0;
    if(buy){
        profit = max(-prices[ind] + solve_using_memoisation(prices,ind+1,0,dp),0 + solve_using_memoisation(prices,ind+1,1,dp));
    }
    else{
        profit = max(prices[ind] + solve_using_memoisation(prices,ind+1,1,dp),0 + solve_using_memoisation(prices,ind+1,0,dp));
    }
    return dp[ind][buy] =profit;
}

int using_tabulation(vector<int>& prices){
    vector<vector<int>> dp(prices.size()+1,(vector<int>(2,0)));

    dp[prices.size()][0] = dp[prices.size()][1] = 0;
    for(int ind = prices.size()-1;ind >=0;ind--){
        for(int buy = 0;buy <= 1;buy++){
            int profit = 0;
        if(buy == 1){
            profit = max(-prices[ind] + dp[ind+1][0],0 + dp[ind+1][1]);
        }
        else{
            profit = max(prices[ind] + dp[ind+1][1],0 + dp[ind+1][0]);
        }
        dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
int solve_using_space_optimisation(vector<int>& prices){
    vector<int> ahead(2,0),cur(2,0);

        ahead[0] = ahead[1] = 0;
        for(int ind = prices.size()-1;ind >=0;ind--){
            for(int buy = 0;buy <= 1;buy++){
                int profit = 0;
            if(buy == 1){
                profit = max(-prices[ind] + ahead[0],0 + ahead[1]);
            }
            else{
                profit = max(prices[ind] + ahead[1],0 + ahead[0]);
            }
            cur[buy] = profit;
            }
            ahead = cur;
        }
        return ahead[1];
}
    int maxProfit(vector<int>& prices) {
        // Solve_using_recursion
        // bool buy = 1;
        // int ind = 0;
        // return solve_using_recursion(prices,ind,buy);


        // solve_using_memoisation 
        // bool buy = 1;
        // int ind = 0;
        // vector<vector<int>> dp(prices.size(),(vector<int>(2,-1)));
        // return solve_using_memoisation(prices,ind,buy,dp);

        return solve_using_space_optimisation(prices);
    }
};
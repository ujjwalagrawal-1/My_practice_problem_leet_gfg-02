class Solution {
public:
int Normalrec(vector<int> &coins,int amount){
    // base case
    if(amount == 0){
        return 0;
    }
    if(amount < 0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i = 0;i<coins.size();i++){
        int val = amount - coins[i];
        int ans = Normalrec(coins,val);
        if(ans != INT_MAX){
            mini = min(mini,ans + 1);
        }
    }
    return mini;
}

int topdown_app_dp(vector<int>& coins,vector<int> &dp,int amount){
    if(amount == 0){
        return 0;
    }
    if(amount < 0){
        return INT_MAX;
    }
    if(dp[amount] != -1){
        return dp[amount];
    }
    int mini = INT_MAX;
    for(int i = 0;i<coins.size();i++){
        int val = amount - coins[i];
        int ans = topdown_app_dp(coins,dp,val);
        if(ans != INT_MAX){
            mini = min(mini,1 + ans);
        }
    }
    dp[amount] = mini;
    return dp[amount];
}
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans  = topdown_app_dp(coins,dp,amount);
        if(ans == INT_MAX){
            ans = -1;
        }
        return ans;

    }
};
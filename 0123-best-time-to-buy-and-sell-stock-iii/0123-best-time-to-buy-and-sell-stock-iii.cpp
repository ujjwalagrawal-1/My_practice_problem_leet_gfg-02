class Solution {
public:
int func(vector<int> &prices,int ind,bool buy,int cap,vector<vector<vector<int>>> &dp){
    if(ind >= prices.size()){
        return 0;
    }
    if(cap <= 0){
        return 0;
    }
    if(dp[ind][buy][cap] != -1){
        return dp[ind][buy][cap];
    }
    int ans = 0;
    if(buy){
        ans = max(-prices[ind] + func(prices,ind+1,0,cap,dp),0 + func(prices,ind+1,1,cap,dp));
    }
    else{
        ans = max(prices[ind] + func(prices,ind+1,1,cap-1,dp),0 + func(prices,ind+1,0,cap,dp));
    }

    return dp[ind][buy][cap] = ans;
}
int using_tabulation(vector<int> &prices,vector<vector<vector<int>>> &dp){
    for(int ind = prices.size()-1;ind >= 0;ind--){
        for(int buy = 0;buy <= 1;buy++){
            for(int cap = 1;cap<=2;cap++){
                int ans = 0;
                if(buy){
                    ans = max(-prices[ind] + dp[ind+1][0][cap],0 + dp[ind+1][1][cap]);
                }
                else{
                    ans = max(prices[ind] + dp[ind+1][1][cap-1],0 + dp[ind+1][0][cap]);
                }

                dp[ind][buy][cap] = ans;
            }
        }
    }
    return dp[0][1][2];
}

int space_optimisation(vector<int> &prices){
    vector<vector<int>> forw(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
    for(int ind = prices.size()-1;ind >= 0;ind--){
        for(int buy = 0;buy <= 1;buy++){
            for(int cap = 1;cap<=2;cap++){
                int ans = 0;
                if(buy){
                    ans = max(-prices[ind] + forw[0][cap],0 + forw[1][cap]);
                }
                else{
                    ans = max(prices[ind] + forw[1][cap-1],0 + forw[0][cap]);
                }

                curr[buy][cap] = ans;
            }
        }
        forw = curr;
    }
    return forw[1][2];
}
    int maxProfit(vector<int>& prices) {
        bool buy = 1;
        int cap = 2;
        int ind = 0;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return func(prices,ind,buy,cap,dp);


        // using tabulation
        // return using_tabulation(prices,dp);
        // tabulation -> spaceoptimisation 
        return space_optimisation(prices);
    }
};
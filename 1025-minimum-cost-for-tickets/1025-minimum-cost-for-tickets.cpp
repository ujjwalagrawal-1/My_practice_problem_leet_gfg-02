class Solution {
public:
int f(vector<int>& days,vector<int> &costs,int i,int ind,vector<vector<int>> &dp){
    if(i > days[days.size()-1] || ind >= days.size()){
        return 0;
    }
    if(dp[i][ind] != -1){
        return dp[i][ind];
    }
    if(days[ind] < i){
        return f(days,costs,i,ind+1,dp);
    }
    if(days[ind] > i){
        return f(days,costs,days[ind],ind,dp);
    }
    int mini = INT_MAX;
    mini = min({mini,f(days,costs,i+7,ind+1,dp)+costs[1],f(days,costs,i+30,ind+1,dp)+costs[2],f(days,costs,i+1,ind+1,dp)+costs[0]});

    return dp[i][ind] = mini;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i = 0;
        vector<vector<int>> dp(400,vector<int> (days.size()+1,-1));
        return f(days,costs,1,0,dp);
    }
};
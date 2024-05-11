class Solution {
public:
int rec(vector<int> & nums,int ind ,int mod,vector<vector<int>>& dp){
    if(ind >= nums.size()){
        if(mod == 0){
            return 0;
        }
        else return INT_MIN;
    }
    if(dp[ind][mod] != -1){
        return dp[ind][mod];
    }
    int take = rec(nums,ind+1,(nums[ind] + mod)%3,dp)+nums[ind];
    int nt = rec(nums,ind+1,(mod)%3,dp);
    return dp[ind][mod] =  max(take,nt); 
}
    int maxSumDivThree(vector<int>& nums) {
        // solve using recursion 
        vector<vector<int>> dp(nums.size(),vector<int>(3,-1));
        int val = rec(nums,0,0,dp);
    }
};
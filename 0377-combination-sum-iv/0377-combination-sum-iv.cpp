class Solution {
public:
int f(vector<int>& nums,int t,vector<int> &dp){
    if(t == 0){
        return 1;
    }
    if(t<0){
        return 0;
    }
    if(dp[t] != -1){
        return dp[t];
    }
    int cnt = 0;
    for(int i = 0;i<nums.size();i++){
        cnt += f(nums,t-nums[i],dp);
    }
    return dp[t] = cnt;
}
    int combinationSum4(vector<int>& nums, int t) {
        vector<int> dp(t+1,-1);
        return f(nums, t,dp);
    }
};

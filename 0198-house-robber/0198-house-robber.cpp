class Solution {
public:
int solve(vector<int>& nums,int n){
    if(n<0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    int ex = solve(nums,n-1) + 0;
    int in = solve(nums,n-2) + nums[n];

    return max(ex,in);
}


int memoisation(vector<int> &nums,int n,vector<int> &dp){
    if(n<0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ex = memoisation(nums,n-1,dp) + 0;
    int in = memoisation(nums,n-2,dp) + nums[n];


    dp[n] = max(ex,in);
    return dp[n];
}
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,0);
        // dp[1] = nums[0];
        // dp[2] = nums[1];
        // int maxi = INT_MIN;
        // for(int j = 3;j<nums.size()+1;j++){
        //     dp[j] = max(dp[j-2],dp[j-3]);
        //     dp[j] += nums[j-1];
        //     // cout<<dp[j]<<" ";
        //     maxi = max(maxi,dp[j]);
        // }
        // return maxi;



        // sec approc
        // return memoisation(nums,nums.size()-1);



        // 3rd approch;
        vector<int> dp(nums.size()+1,-1);
        return memoisation(nums,nums.size()-1,dp);
    }
};
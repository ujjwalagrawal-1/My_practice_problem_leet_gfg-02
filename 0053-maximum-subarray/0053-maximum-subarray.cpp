class Solution {
public:
    int f(vector<int> &nums, int i,vector<int> &dp) {
        if (i < 0) {
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int not_taken = nums[i];
        int taken = nums[i] + f(nums,i-1,dp) ; 
        return dp[i] = max(not_taken,taken);
    }
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;vector<int> dp(nums.size(),-1);
        for(int i = nums.size()-1;i>=0;i--){
            maxi = max(maxi,f(nums,i,dp));
        }
        return maxi;
    }
};

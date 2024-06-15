class Solution {
public:
    int f(int ind, vector<int>&nums, int tar, vector<vector<int>>&dp){
        if(tar==0){
            return 1;
        }
        if(ind>=nums.size()){
            return INT_MIN;
        }
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        
        int notpick=f(ind+1, nums, tar, dp);
        int pick=INT_MIN;

        if(nums[ind]<=tar){
            pick=1+f(ind+1, nums, tar-nums[ind], dp);
        }

        return dp[ind][tar]=max(pick, notpick);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));

        int ans=f(0, nums, target, dp);
        if(ans<=0){
            return -1;
        }
        return ans-1;
    }
};
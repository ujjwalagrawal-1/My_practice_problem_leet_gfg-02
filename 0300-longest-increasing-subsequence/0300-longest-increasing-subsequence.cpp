class Solution {
public:
    int solve(vector<int> &nums, int ind, int p, vector<vector<int>> &dp){
        int n = nums.size();
        if (ind == n)
            return 0;
        if (dp[ind][p + 1] != -1) 
            return dp[ind][p + 1];

        int maxLen = 0 + solve(nums, ind + 1, p, dp);
        if (p == -1 || nums[ind] > nums[p])
            maxLen = max(maxLen, 1 + solve(nums, ind + 1, ind, dp));
            
        dp[ind][p + 1] = maxLen;
        return dp[ind][p+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        // return solve(nums, 0, -1, dp);
        for(int ind = n-1;ind>=0;ind--){
            for(int p = ind-1;p>=-1;p--){
                int maxLen = 0 + dp[ind + 1][p+1];
                if (p == -1 || nums[ind] > nums[p])
                    maxLen = max(maxLen, 1 + dp[ind + 1][ind+1]);
                    
                dp[ind][p + 1] = maxLen;
            }
        }
        return dp[0][0];
    }
   

};
class Solution {
public:
    int solve_using_recursion(vector<int>& nums, int s, int e) {
        if (s == e) {
            return nums[s];
        }

        int a = nums[s] - solve_using_recursion(nums, s + 1, e);
        int b = nums[e] - solve_using_recursion(nums, s, e - 1);

        return max(a, b);
    }
    int solve_using_Memoisation(vector<int>& nums, int s, int e,
                                vector<vector<int>>& dp) {
        if (s == e) {
            return nums[s];
        }
        if (dp[s][e] != -1) {
            return dp[s][e];
        }
        int a = nums[s] - solve_using_Memoisation(nums, s + 1, e, dp);
        int b = nums[e] - solve_using_Memoisation(nums, s, e - 1, dp);

        return dp[s][e] = max(a, b);
    }
    int solve_using_tabulation(vector<int>& nums, int n,
                               vector<vector<int>>& dp) {
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        int i = nums.size();
        for (int s = n - 1; s >= 0; s--) {
            for (int e = i; e < nums.size(); e++) {
                int a = nums[s] - dp[s + 1][e];
                int b = nums[e] - dp[s][e - 1];
                dp[s][e] = max(a, b);
            }
            i--;
        }
        return dp[0][n - 1];
    }
    bool predictTheWinner(vector<int>& nums) {
        // using recursion
        // return solve_using_recursion(nums,0,nums.size()-1)>0;

        // using Memoiasation
        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solve_using_Memoisation(nums,0,n-1,dp)>=0;
        // Solve using tabulation
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        return solve_using_tabulation(nums, n, dp) >= 0;
    }
};
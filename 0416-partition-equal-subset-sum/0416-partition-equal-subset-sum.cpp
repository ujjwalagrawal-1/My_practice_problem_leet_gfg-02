class Solution {
public:

    // This Is recursive Solution Which Gives TLE On the large TestCases So Moving Towards More Optimal Solution
    bool Partition_recursively(vector<int> &nums, int mid, int index) {
        if (mid == 0) {
            return true;
        }
        if (index < 0 || mid < 0) {
            return false;
        }

        bool include = Partition_recursively(nums, mid - nums[index], index - 1);
        bool exclude = Partition_recursively(nums, mid, index - 1);

        return include || exclude;
    }

    // Using Memoisation
    bool partition_dp(vector<int> &nums, int mid, int index, vector<vector<int>> &dp) {
        if (mid == 0) {
            return true;
        }
        if (index < 0 || mid < 0) {
            return false;
        }
        if (dp[index][mid] != -1) {
            return dp[index][mid];
        }

        bool include = partition_dp(nums, mid - nums[index], index - 1, dp);
        bool exclude = partition_dp(nums, mid, index - 1, dp);

        dp[index][mid] = include || exclude;
        return dp[index][mid];
    }

    // Tabulation
    bool partition_using_tabulation(vector<int> &nums, int mid) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(mid + 1, 0));

        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= mid; j++) {
                bool include = false;
                if (j - nums[i - 1] >= 0) {
                    include = dp[i - 1][j - nums[i - 1]];
                }
                bool exclude = dp[i - 1][j];

                dp[i][j] = include || exclude;
            }
        }

        return dp[nums.size()][mid];
    }

    bool canPartition(vector<int>& nums) {
        int mid = 0;
        // making single integer so that extra space
        // not needed in only calculating the sum and divide it by.
        for (auto itr : nums) {
            mid += itr;
        }

        // If sum is odd return false;
        if (mid % 2 != 0) return false;
        mid /= 2;

        // Answer coming from recursion;
        // return Partition_recursively(nums,mid,nums.size()-1);

        // Memoisation
        // vector<vector<int>> dp(nums.size(),vector<int>(mid+1,-1));
        // return partition_dp(nums,mid,nums.size()-1,dp);

        // Tabulation
        return partition_using_tabulation(nums, mid);
    }
};

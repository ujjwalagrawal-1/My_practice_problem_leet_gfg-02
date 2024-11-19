class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        long long ans = 0;
        long long curr_sum = 0;
        unordered_map<int, int> mp;
        while (j < nums.size()) {
            curr_sum += nums[j];
            mp[nums[j]]++;
            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                if (mp.size() == k) {
                    ans = max(curr_sum, ans);
                }
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                curr_sum -= nums[i];
                i++, j++;
            }
        }
        return ans;
    }
};
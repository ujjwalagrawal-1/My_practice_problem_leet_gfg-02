class Solution {
public:
    bool c(vector<int> &nums, int mid, int t) {
        int l = 0, r = 0;
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            if (r - l + 1 == mid) {
                if (sum >= t) {
                    return true;
                }
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return false;
    }

    int minSubArrayLen(int t, vector<int>& nums) {
        int s = 1, e = nums.size();
        int result = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (c(nums, mid, t)) {
                result = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return result > 0 ? result : 0;
    }
};

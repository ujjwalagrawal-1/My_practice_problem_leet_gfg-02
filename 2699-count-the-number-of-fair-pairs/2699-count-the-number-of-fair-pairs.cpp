typedef long long ll;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;i++){
            auto itr = upper_bound(nums.begin()+i+1,nums.end(),upper - nums[i]);
            auto it = lower_bound(nums.begin()+i+1,nums.end(),lower - nums[i]);
            ans += itr - it;
        }
        return ans;
    }
};
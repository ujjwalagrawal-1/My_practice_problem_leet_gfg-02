class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            bool fl = 0;
            if((i - k >= 0 && (nums[i] > nums[i-k])) && (i+k < nums.size() && (nums[i] > nums[i+k]))){
                ans += nums[i];
                // continue;
            }
            if(i - k  < 0 && (i+k < nums.size() && (nums[i] > nums[i+k]))){
                ans += nums[i];
            }
            if(i + k >= nums.size() && (nums[i] > nums[i-k])){
                ans += nums[i];
            }
        }
        return ans;
    }
};
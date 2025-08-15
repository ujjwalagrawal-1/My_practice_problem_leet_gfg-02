class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size() <= 2)return true;
        int tsum = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] + nums[i-1] >= m)return true;
        }
        return false;
    }
};
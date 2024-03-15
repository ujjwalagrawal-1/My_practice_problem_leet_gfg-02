class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            mini = min(mini,nums[i]);
        }
        int ans = 0;
        for(auto itr:nums){
            ans += abs(itr - mini);
        }
        return ans;
    }
};
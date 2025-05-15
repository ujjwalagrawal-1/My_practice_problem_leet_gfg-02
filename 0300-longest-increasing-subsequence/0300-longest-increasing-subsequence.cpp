class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            auto itr = upper_bound(ans.begin(),ans.end(),nums[i]-1) - ans.begin();
            if(itr >= ans.size()){
                ans.push_back(nums[i]);
            }
            else{
                ans[itr] = nums[i];
            }
        }
        return ans.size();
    }
};
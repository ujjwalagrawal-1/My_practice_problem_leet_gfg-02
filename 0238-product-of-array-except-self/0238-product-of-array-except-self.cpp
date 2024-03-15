class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int multi = 1;
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        int lft = 1;
        for(int i = 0;i<nums.size()-1;i++){
            left[i+1] = lft *= nums[i];
            cout<<left[i+1]<<" ";
        }
        int rgt = 1;
        for(int i = nums.size()-1;i >= 1;i--){
            right[i-1] = rgt *= nums[i];
        }
        
        nums[0] = right[0];
        nums[nums.size()-1] = left[nums.size()-1];
        for(int i = 1;i<nums.size()-1;i++){
            nums[i] = left[i]*right[i];
        }
        return nums;
    }
};
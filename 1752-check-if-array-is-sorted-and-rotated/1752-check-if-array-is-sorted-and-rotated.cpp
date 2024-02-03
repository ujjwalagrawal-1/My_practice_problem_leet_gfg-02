class Solution {
public:
    bool check(vector<int>& nums) {
        int ind = nums.size()-1,mini = nums[0];
        for(int i = nums.size()-1;i>=1;i--){
           if(nums[i]>=nums[i-1]){
               ind = i-1;
           }
           else{
               break;
           }
        }
        int i = 0;
        while(i < nums.size()-1){
            if(nums[(i+ind)%nums.size()] > nums[(i+ind+1)%nums.size()]){
                return false;
            }
            i++;
        }
        return true;

    }
};
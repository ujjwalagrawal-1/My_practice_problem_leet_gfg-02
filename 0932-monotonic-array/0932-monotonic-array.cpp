class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag = 0;
        if(nums.size() == 1){
            return true;
        }
        for(int i = 0;i<nums.size()-1;i++){
            int j = i + 1;
            if(nums[i] >= nums[j]){
                continue;
            }
            else{
                flag = 1;
                break;
            }
        }
        if(flag){
            for(int i = 0;i<nums.size()-1;i++){
            int j = i + 1;
            if(nums[i] <= nums[j]){
                flag = 0;
                continue;
            }
            else{
                flag = 1;
                break;
            }
        }
        }
        return flag == 1 ?false : true ;
    }
};
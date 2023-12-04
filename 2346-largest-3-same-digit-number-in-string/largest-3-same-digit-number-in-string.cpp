class Solution {
public:
    string largestGoodInteger(string nums) {
        string ans = "";
        int s = 0;
        int digi = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
                if(digi >= nums[i]){
                    continue;
                }
                else{
                ans = "";
                ans += nums.substr(i,3);
                digi = nums[i];
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = nums[0];
        for(int i = 0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        int ms = 1;
        // int cs = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == maxi){
                int j = i;
                while(j<nums.size() && nums[j] == maxi){
                    j++;
                }
                ms = max(ms,j - i);
                i = j;
            }
        }
        return ms;
    }
};
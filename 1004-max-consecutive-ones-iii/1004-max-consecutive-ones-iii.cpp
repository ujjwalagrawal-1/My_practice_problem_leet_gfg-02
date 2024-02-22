class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<nums.size()){
            if(nums[j] == 0){
                k--;
            }
            if(k>=0){
                ans = max(j-i+1,ans);
            }
            if(k < 0){
                while(nums[i] != 0){
                    i++;
                }
                i++;
                k++;
            }
            j++;
        }
        return ans;
    }
};
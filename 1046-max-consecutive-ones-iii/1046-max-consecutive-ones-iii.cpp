class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int i = 0,j = 0;
        while(j<nums.size()){
            if(nums[j] == 0){
                k--;
            }
            if(k < 0){
                while(nums[i] != 0){
                    i++;
                }
                i++;
                k++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
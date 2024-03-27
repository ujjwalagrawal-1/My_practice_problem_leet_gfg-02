class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;int j = 0;
        int cnt = 0;
        int multi = 1;
        if(k <= 1){
            return 0;
        }
        while(j<nums.size()){
            multi *= nums[j]; 
             while(multi >= k){
                    multi /= nums[i];
                    i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
};
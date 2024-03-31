class Solution {
public:
int fun(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int val = 0;
        int ans = 0;
        while(j<nums.size()){
            val += nums[j]%2;
            while(i<=j && val > k){
                val -= nums[i]%2 ;
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};
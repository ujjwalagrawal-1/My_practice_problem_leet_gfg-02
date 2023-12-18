class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin() , nums.end() , greater<int> ()) ;
        int n = nums.size() ;
        int ans = ((nums[0]*nums[1]) -  (nums[n-1]*nums[n-2])) ;
        return ans ;
    }
};
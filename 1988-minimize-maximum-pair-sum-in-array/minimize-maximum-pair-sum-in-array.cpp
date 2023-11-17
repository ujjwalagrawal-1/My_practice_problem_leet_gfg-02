class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;int j = nums.size() - 1;
        int sum = 0;int maxi = 0;
        while(i<j){
            sum += nums[i]+nums[j];
            i++;j--;
            maxi = max(maxi,sum);
            sum = 0;
        }
        return maxi;
    }
};
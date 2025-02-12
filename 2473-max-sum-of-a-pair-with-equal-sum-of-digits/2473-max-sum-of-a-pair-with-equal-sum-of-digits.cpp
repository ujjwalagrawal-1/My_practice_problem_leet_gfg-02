class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> veci(144,0);
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int sum = 0;
            int  t = nums[i];
            while(nums[i]){
                sum += nums[i]%10;
                nums[i]/=10;
            }
            if(veci[sum]!= 0){
                maxi = max(maxi,t + veci[sum]);
            }
            veci[sum] = max(veci[sum],t);
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};
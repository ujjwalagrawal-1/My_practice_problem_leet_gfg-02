class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = INT_MIN,mini = INT_MAX,cmax_sum = 0,cmin_sum = 0;
        for(int i = 0;i < nums.size();i++){
            cmax_sum += nums[i];
            cmin_sum += nums[i];
            maxi = max(maxi,cmax_sum);
            mini = min(mini,cmin_sum);
            if(cmax_sum <= 0)cmax_sum = 0;
            if(cmin_sum >= 0)cmin_sum = 0;
        }
        return max(maxi,abs(mini));
    }
};
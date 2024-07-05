class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = 0, minsum = 0, maxi = INT_MIN, mini = INT_MAX;
        for(int it : nums){
            maxsum += it;
            minsum += it;
            maxi = max(maxi, maxsum);
            mini = min(mini, minsum);
            if(minsum > 0) minsum = 0;
            if(maxsum < 0) maxsum = 0;
        }
        
        return max(maxi, abs(mini));
    }
};
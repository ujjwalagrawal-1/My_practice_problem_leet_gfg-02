class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastindex = 0;
        int mini = -1,maxi = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > maxK || nums[i] < minK){
                lastindex = i+1;
                continue;
            }
            if(nums[i] == maxK)maxi = i;
            if(nums[i] == minK)mini = i;
            ans += max(min(maxi,mini) - lastindex + 1 , 0);
        }
        return ans;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0;
        map<int,int>mp;
        mp[0]++;
        int sum = 0,ans = 0;
        while(i<nums.size()){
            sum += nums[i];
            if(mp.count(sum - k)){
                ans += mp[sum-k];
            }
            mp[sum]++;
            i++;
        }
        return ans;
    }
};
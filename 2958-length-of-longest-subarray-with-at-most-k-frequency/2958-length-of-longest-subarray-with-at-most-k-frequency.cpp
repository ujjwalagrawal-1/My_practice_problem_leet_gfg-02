class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i = 0;int j = 0;
        int ans = 0;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]] > k){
                while(mp[nums[j]] > k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            if(mp[nums[j]] <=k){
                ans = max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};
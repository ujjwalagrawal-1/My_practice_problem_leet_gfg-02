class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size()+1,1);
        vector<int> hash(nums.size()+1,-1);
        // iota()
        for(int i = 1;i < nums.size();i++){
            for(int prev = 0;prev <= i-1;prev++){
                if(nums[i]%nums[prev] == 0 && dp[i] < dp[prev]+1){
                    dp[i] = dp[prev]+1;
                    hash[i] = prev;
                }
            }
        }
        int ans = -1,prevind =-1;
        for(int i = 0;i<nums.size()+1;i++){
            if(dp[i] > ans){
                ans = dp[i];
                prevind = i;
            }
        }
        vector<int> result;
        while(prevind != -1) {
            result.push_back(nums[prevind]);
            prevind = hash[prevind];
        }
        return result;
    }
};
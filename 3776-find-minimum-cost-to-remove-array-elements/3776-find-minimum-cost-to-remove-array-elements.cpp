class Solution {
public:
int dp[1001];
int f(vector<int> & nums,int i,int prev){
    if(i >= nums.size()){
        return nums[prev];
    }
    if(nums.size() - i-1 == 0){
        return max(nums[i],nums[prev]);
    }
    if(dp[prev] != -1){
        return dp[prev];
    }
    int ans = min({f(nums,i+2,prev) + max(nums[i],nums[i+1]),f(nums,i+2,i) + max(nums[prev],nums[i+1]),f(nums,i+2,i+1) + max(nums[i],nums[prev])});

    return dp[prev] = ans;
}
    int minCost(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        memset(dp,-1,sizeof(dp));
        return f(nums,1,0);
    }
};
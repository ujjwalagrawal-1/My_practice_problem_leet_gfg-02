class Solution {
public:
int solve(vector<int> &nums,int k,int num,vector<vector<int>> &dp){
    if(k == 0){
        if(num == 0){
            return 1;
        }
        return 0;
    }
    if(dp[k][num] != -1){
        return dp[k][num];
    }
    int t = 0;
    for(int i = 0;i<nums.size();i++){
        if(k == 3){
            t += solve(nums,k-1,nums[i],dp);
        }
        else{
            t  += solve(nums,k-1,num&nums[i],dp);
        }
    }
    return dp[k][num] = t;
}
    int countTriplets(vector<int>& nums) {
        // vector<vector<int>> dp();
        int ans = 0;
        vector<vector<int>> dp(4,vector<int>(1000000,-1));
        ans += solve(nums,3,0,dp);
        return ans;
        }
};
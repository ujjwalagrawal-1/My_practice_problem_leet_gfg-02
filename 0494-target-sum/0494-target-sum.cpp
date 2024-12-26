class Solution {
public:
int dp[21][20001];
int f(vector<int>& nums,int target,int i,int csum){
    if(i == nums.size()){
        if(csum == target){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][csum] != -1){
        return dp[i][csum];
    }
    return dp[i][csum] = f(nums,target,i+1,csum+nums[i]) + f(nums,target,i+1,csum);

}
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int tsum = 0;int x = nums.size();
        for(auto& itr : nums){
            tsum += itr;
        }
        int tar = (tsum - target);
        if(tar%2 == 1 || tar < 0){
            return 0;
        }
        tar /= 2;
        return f(nums,tar,0,0);
    }
};
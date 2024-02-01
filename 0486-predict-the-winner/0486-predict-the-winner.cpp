class Solution {
public:
int solve_using_recursion(vector<int> &nums,int s,int e){
    if(s == e){
        return nums[s];
    }

    int a = nums[s] - solve_using_recursion(nums,s+1,e);
    int b = nums[e] - solve_using_recursion(nums,s,e-1);

    return max(a,b);
}
int solve_using_Memoisation(vector<int>& nums,int s,int e,vector<vector<int>>& dp){
    if(s == e){
        return nums[s];
    }
    if(dp[s][e] != -1){
        return dp[s][e];
    }
    int a = nums[s] - solve_using_Memoisation(nums,s+1,e,dp);
    int b = nums[e] - solve_using_Memoisation(nums,s,e-1,dp);

    return dp[s][e] = max(a,b);
}
    bool predictTheWinner(vector<int>& nums) {
        // using recursion
        // return solve_using_recursion(nums,0,nums.size()-1)>0;

        // using Memoiasation
        if(nums.size() == 1){
            return true;
        }
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve_using_Memoisation(nums,0,n-1,dp)>=0;
    }
};
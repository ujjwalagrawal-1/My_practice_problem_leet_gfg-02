class Solution {
public:
int solve(vector<int>& nums,int n){
    if(n<0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    int ex = solve(nums,n-1) + 0;
    int in = solve(nums,n-2) + nums[n];

    return max(ex,in);
}


int memoisation(vector<int> &nums,int n,vector<int> &dp){
    if(n<0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ex = memoisation(nums,n-1,dp) + 0;
    int in = memoisation(nums,n-2,dp) + nums[n];


    dp[n] = max(ex,in);
    return dp[n];
}

int tabulation(vector<int> &nums,int n){
    vector<int> dp(n,0);
    dp[0] = nums[0]; 
    // dp[1] = nums[0];
    // 1->n;
        for(int i = 1;i < n;i++){
            int in = 0;
            if(i>=2)
            in = dp[i-2] + nums[i];

            int ex = dp[i-1] + 0;
            dp[i] = max(ex,in);
        }
    return dp[n-1];
    
}


int spaceoptimisation(vector<int> nums){
    int prev2 = 0;
    int prev = nums[0];

    for(int i = 1;i < nums.size();i++){
            int in = nums[i];
            if(i >=2)
            in += prev2;

            int ex = prev + 0;
            int ans = max(ex,in);
            prev2 = prev;
            prev = ans;
        }
        return prev;
}
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,0);
        // dp[1] = nums[0];
        // // dp[2] = nums[1];
        // int maxi = INT_MIN;
        // for(int j = 3;j<nums.size()+1;j++){
        //     dp[j] = max(dp[j-2],dp[j-3]) + nums[j-1];
        //     // cout<<dp[j]<<" ";
        //     maxi = max(maxi,dp[j]);
        // }
        // return maxi;



        // sec approc
        // return memoisation(nums,nums.size()-1);



        // 3rd approch;
        // vector<int> dp(nums.size()+1,-1);
        // return memoisation(nums,nums.size()-1,dp);



        //4th approch
        return spaceoptimisation(nums);
    }
};
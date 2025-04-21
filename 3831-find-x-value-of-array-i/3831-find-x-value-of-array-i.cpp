long long dp[100001][6];
class Solution {
public:
long long f(vector<int> &nums,int want,int pro,int i,int k){
    if(i >= nums.size()){
        return 0;
    }
    if(dp[i][pro+1] != -1){
        return dp[i][pro+1];
    }
    long long a = 0,b = 0,cnt = 0;
    if(pro == -1){
        a = f(nums,want,pro,i+1,k);
        if(nums[i] == want)cnt++;
        b = f(nums,want,nums[i],i+1,k);
    }
    else{
        if((pro*nums[i])%k == want){
            cnt++;
        }
        b = f(nums,want,(nums[i]*pro*1LL)%k,i+1,k);
    }
    return dp[i][pro+1] = a+b+cnt;
}
    vector<long long> resultArray(vector<int>& nums, int k) {
        for(int i = 0;i<nums.size();i++){
            nums[i] %= k;
        }
        vector<long long> veci(k);
        for(int i = 0;i<k;i++){
            memset(dp,-1,sizeof(dp));
            veci[i] = f(nums,i,-1,0,k);
        }

        return veci;
    }
};
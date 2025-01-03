class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0ll;int ans = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
        }
        long long cs = 0;
        for(int i = 0;i<nums.size()-1;i++){
            cs += nums[i];
            if(cs >= sum-cs){
                ans++;
            }
        }
        return ans;

    }
};
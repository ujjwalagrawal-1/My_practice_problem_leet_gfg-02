class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        int cnt =0;
        long long  ans = 0;
        int i = 0,j = 0;
        while(j<nums.size()){
            if(nums[j] == maxi){
                cnt++;
            }
            while(cnt >= k){
                ans += nums.size()-j;
                if(nums[i] == maxi){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ans;

    }
};
typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll maxi = LLONG_MIN;
        for(int i = 0;i<nums.size();i++){
            maxi = max(maxi,nums[i]*1ll);
        }
        ll i = 0,j = 0,cnt = 0;
        ll ans = 0;
        while(j < nums.size()){
            if(nums[j] == maxi){
                cnt++;
            }
            while(cnt >= k){
                if(nums[i] == maxi){
                    cnt--;
                }
                ans += nums.size() - j;
                i++;
            }
            j++;
        }
        return ans;
    }
};
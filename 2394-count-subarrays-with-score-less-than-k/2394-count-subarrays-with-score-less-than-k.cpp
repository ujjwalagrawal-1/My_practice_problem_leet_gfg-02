typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll sum = 0;
        ll i = 0;
        ll j = 0;
        ll cnt = 0;
        while(j < nums.size()){
            sum += nums[j];
            while(i <= j && sum*(j-i+1)*1ll >= k){
                sum -= nums[i];
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
};
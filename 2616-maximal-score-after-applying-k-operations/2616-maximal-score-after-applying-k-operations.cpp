typedef long long ll;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ll ans =0;
        priority_queue<ll> pq;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k--){
            ll topp = pq.top();
            ans += topp;
            pq.pop();
            pq.push(ceil(topp*1.0/3.0));
        }
        return ans;
    }
};
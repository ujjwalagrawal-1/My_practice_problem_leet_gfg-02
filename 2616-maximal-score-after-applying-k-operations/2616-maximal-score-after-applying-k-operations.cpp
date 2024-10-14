typedef long long ll;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ll ans =0;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size() >  k){
                pq.pop();
            }
        }
        priority_queue<ll> pq2;
        while(!pq.empty()){
            pq2.push(pq.top());
            pq.pop();
        }
        while(k--){
            ll topp = pq2.top();
            ans += topp;
            pq2.pop();
            pq2.push(ceil(topp*1.0/3.0));
        }
        return ans;
    }
};
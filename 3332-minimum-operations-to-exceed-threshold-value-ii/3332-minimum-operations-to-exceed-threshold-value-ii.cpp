typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll w = 0;
        while(w < nums.size()){
            pq.push(nums[w]);
            w++;
        }
        w = 0;
        while(!pq.empty() && pq.top() < k){
            ll a = pq.top();pq.pop();
            ll b = pq.top();pq.pop();
            pq.push(min(a,b)*2ll + max(a,b));
            w++;
        }
        return w;
    }
};
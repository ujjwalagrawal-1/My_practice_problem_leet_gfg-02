typedef long long ll;
class Solution {
public:
    ll findMaxi(vector<int>& piles) {
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    ll findH(vector<int>& p, ll hrs) {
        ll ans = 0;
        for(int i = 0; i < p.size(); i++) {
            ans += ceil((double)p[i]/ (double)hrs);  // This simulates ceil(p[i] / hrs)
        }
        return ans;
    }

    ll minEatingSpeed(vector<int>& p, ll h) {
        ll s = 1; 
        ll e = findMaxi(p);
        ll ans = -1;
        while(s <= e) {
            ll mid = s + (e - s) / 2;
            ll hui = findH(p, mid);
            if(hui <= h) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
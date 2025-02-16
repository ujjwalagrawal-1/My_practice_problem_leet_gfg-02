using ll = long long;
class Solution {
public:
    long long maxWeight(vector<int>& pz) {
        sort(pz.begin(),pz.end());
        ll cnt = 0;
        ll i = 0,j = pz.size()-1;
        ll n = pz.size()/4;
        ll e = ceil(n*1.0/2.0);
        ll od = floor(n*1.0/2.0);
        while(e--){
            cnt += pz[j];
            j--;
        }
        while(od--){
            j--;
            cnt += pz[j];
            j--;
        }
        return cnt;
    }
};
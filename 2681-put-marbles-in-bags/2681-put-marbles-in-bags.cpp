typedef long long ll;
class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        if(k == w.size()){
            return 0;
        }
        vector<ll> veci;
        for(int i = 0;i<w.size()-1;i++){
            veci.push_back(w[i] + w[i+1]);
        }
        ll a = 0,b = 0;
        sort(veci.begin(),veci.end());
        for(int i = 0;i<k-1;i++){
            a += veci[i];
            b += veci[veci.size()-i-1];
        }
        return b-a;
    }
};
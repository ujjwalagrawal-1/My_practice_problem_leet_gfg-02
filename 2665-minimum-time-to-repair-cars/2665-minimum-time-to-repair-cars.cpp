typedef long long ll;
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll ans = 0;
        ll s = 0;
        ll e = 1e14;
        while(s <= e){
            ll mid = s + (e - s)/2;
            ll sum = 0;
            for(int i = 0;i<ranks.size();i++){
                sum += sqrt(mid/ranks[i]);
            }
            if(cars > sum){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return s;
    }
};
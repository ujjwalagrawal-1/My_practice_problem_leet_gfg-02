typedef long long ll;


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<ll,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        ll cnt = 1;
        for(auto itr : mp){
            ll start = itr.first;
            if(start == 1){
                continue;
            }
            ll startpower = 1;
            ll ans = 0;
            while(mp.find(ll(pow(start,startpower))) != mp.end()){
                ll ti = mp[ll(pow(start,startpower))];
                startpower *= 2;
                if(ti >= 2){
                    ans += 2;
                }
                else if(ti == 1){
                    ans += 1;
                    break;
                }
                else{
                    break;
                }
            }
            if(ans%2 == 0 && ans>0){
                ans -= 1;
            }
            cnt = max(cnt,ans);
        }
        if (mp.find(1) != mp.end()) {
            if(mp[1]%2==0)mp[1]--;
            cnt = max(cnt, 1ll*mp[1]);
        }
        return cnt;
    }
};
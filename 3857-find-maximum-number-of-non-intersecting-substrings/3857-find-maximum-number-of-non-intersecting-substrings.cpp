using ll = long long;
typedef vector<ll> vecl;typedef vector<vecl> dvecl;
class Solution {
public:
    int maxSubstrings(string w) {
    map<ll,vecl> mp;

    for(int i = 0; i < w.size(); i++) {
        mp[w[i] - 'a'].push_back(i);
    }

    dvecl temp;
    for(auto& itr : mp){
        vecl& t = itr.second;
        for(int i = 0; i < t.size() - 1; i++) {
            auto itr = lower_bound(t.begin(),t.end(),t[i]+3)-t.begin();
            if(itr == t.size()){
                break;
            }
            else{
                temp.push_back({t[i],t[itr]});
            }
        }
    }
    if(temp.empty()) return 0;
    sort(temp.begin(), temp.end(), [](vecl& a, vecl& b){
        return a[1] < b[1];
    });
    ll cnt = 1;
    ll tk = temp[0][1];

    for(ll j = 1; j < temp.size(); j++) {
        if(temp[j][0] > tk){
            cnt++;
            tk = temp[j][1];
        }
    }

    return cnt;
}

};
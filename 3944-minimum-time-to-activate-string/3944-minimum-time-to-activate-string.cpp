class Solution {
public:
    using ll = long long;
    int minTime(string st, vector<int>& order, int k) {
        int n = order.size();
        auto f = [&](int mid){
            string temp = st;
            ll cnt = 0;
            // int prev = -1;
            for(int i = 0;i<=mid;i++){
                temp[order[i]] = '*';
            }
            int e = 0;
            int prev = -1;
            for(int i = 0;i<temp.size();i++){
                if(temp[i] == '*'){
                    // cout<<"star at i = "<<i<<endl;
                    ll lft = (i)-prev;
                    ll rgt = n - i;
                    // cout<<lft<<" "<<rgt<<"  "<<endl;
                    cnt += 1LL*lft*rgt;
                    if(cnt >= k){
                        return true;
                    }
                    prev = i;
                    // e++;
                }
            }
            // cnt -= mid;
            return cnt >= k;
        };
        int s = 0;
        int e = order.size()-1;
        int ans = order.size();
        while(s <= e){
            int mid = s + (e - s)/2;
            // cout<<"called for mid "<<mid<<endl;
            bool val = f(mid);
            // cout<<val<<"  "<<s<<"  "<<e<<endl;
            if(val){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans >= order.size() ? -1 : ans;
    }
};
// a*bc*cd*ef©leetcode
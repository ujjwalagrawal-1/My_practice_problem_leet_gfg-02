class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        int x = offers.size();
        vector<int> a(x);
        for(int i = 0;i<x;i++){
            a[i] = offers[i][0];
        }
        vector<int> dp(x,-1);
        function<int(int)> f = [&](int i){
            if(i >= x){
                return 0;
            }
            if(dp[i] != -1){
                return dp[i];
            }
            int ans = 0;
            auto in = upper_bound(a.begin(),a.end(),offers[i][1]) - a.begin();
            ans  = max(f(in)+offers[i][2],f(i+1));
            return dp[i] = ans;
        };
        return f(0);
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        long long mask1 = (long long)0;
        long long mask2 = (long long)0;
        int n = a.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            mask1 = (mask1 ^ (1ll << a[i]));
            mask2 = (mask2 ^ (1ll << b[i]));
            long long temp = (mask1&mask2);
            int cnt = 0;
            while(temp > 0){
                long long rsb = (temp&(-temp));
                temp = temp-rsb;
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
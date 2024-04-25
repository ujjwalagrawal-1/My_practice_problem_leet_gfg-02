class Solution {
public:
    int f(string &s, int k, int ind, char ch,vector<int> &dp) {
        if (ind >= s.size()) {
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }

        int a = 0, b = 0, c = 0, d = 0, e = 0;

        if (ch == '/') {
            if (s[ind] != '/') {
                a = 1 + f(s, k, ind + 1, s[ind],dp);
                b = f(s, k, ind + 1, ch,dp);
            } else {
                a = f(s, k, ind + 1, s[ind],dp);
                b = f(s, k, ind + 1, ch,dp);
            }
        } else {
            if (abs(s[ind] - ch) <= k) {
                c = 1 + f(s, k, ind + 1, s[ind],dp);
                d = f(s, k, ind + 1, ch,dp);
            } else {
                e = f(s, k, ind + 1, ch,dp);
            }
        }

        return dp[ind] =  max({a, b, c, d, e});
    }

    int longestIdealString(string s, int k) {
        // using recursion
        // return f(s, k, 0, '/');

        // using memoisation
        vector<int> dp(s.size()+1,-1);
        return f(s,k,0,'/',dp);
    }
};

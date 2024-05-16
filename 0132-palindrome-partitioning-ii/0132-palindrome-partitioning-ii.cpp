class Solution {
public:
    bool isPlaindrome(string str) {
        int s = 0;
        int e = str.size() - 1;
        while (s <= e) {
            if (str[s] != str[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    int f(string s, int ind,vector<int> &dp) {
        if (ind >= s.size()) {
            return 0;
        }
        if(dp[ind]!= -1){
            return dp[ind];
        }
        int ans = INT_MAX;
        for (int i = ind; i < s.size(); i++) {
            string e = s.substr(ind, i - ind + 1);
            if (isPlaindrome(e)){
                ans = min(ans,f(s,i+1,dp)+1);
            }
        }
        return dp[ind] =  ans;
    }
    int minCut(string s) { 
        vector<int> dp(s.size()+1,-1);
        return f(s, 0,dp)-1; 
    }
};
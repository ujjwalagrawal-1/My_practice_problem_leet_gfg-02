class Solution {
public:
int fun(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
    int n = s1.size();
    int m = s2.size();
    if(i >= n || j >= m){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s1[i] == s2[j]){
        dp[i][j] =  fun(s1,s2,i+1,j+1,dp) + 1;
    }
    else{
        dp[i][j] = max(fun(s1,s2,i+1,j,dp),fun(s1,s2,i,j+1,dp));
    }

    return dp[i][j];
}
    int longestPalindromeSubseq(string s) {
        int i = 0,j = 0;
        string s1 =s;
        reverse(s.begin(),s.end());
        string s2  = s;
        vector<vector<int>> dp(s.size() + 1,vector<int>(s.size() + 1,0));
        // return fun(s1,s2,0,0,dp);

        // using tabulation 
        for(int i = s.size()-1;i >= 0;i--){
            for(int j = s.size()-1;j>=0;j--){
                if(s1[i] == s2[j]){
                    dp[i][j] =  dp[i+1][j+1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
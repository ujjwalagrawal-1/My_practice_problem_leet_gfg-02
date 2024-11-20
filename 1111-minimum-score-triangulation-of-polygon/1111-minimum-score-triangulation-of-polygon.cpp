class Solution {
public:
long long f(vector<int> &veci,int i,int j,vector<vector<long long>> & dp){
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    long long mini = INT_MAX;
    for(int k = i;k <= j-1;k++){
        mini = min(mini,f(veci,i,k,dp) + f(veci,k+1,j,dp) + 1ll*veci[i-1]*veci[k]*veci[j]);
    }
    return dp[i][j] =  mini;
}
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<long long>> dp(n+1,vector<long long> (n+1, 0));

        for(int i = n-2;i >= 1;i--){
            for(int j = 2;j<= n-1;j++){
                if(i == j){
                    continue;
                }
                long long mini = INT_MAX;
                for(int k = i;k <= j-1;k++){
                    mini = min(mini,f(values,i,k,dp) + f(values,k+1,j,dp) + 1ll*values[i-1]*values[k]*values[j]);
                }
                dp[i][j] =  mini;
            }
        }

        return dp[1][n-1];
        // return f(values,1,n-1,dp);
    }
};
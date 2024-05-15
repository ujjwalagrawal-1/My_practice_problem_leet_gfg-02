class Solution {
public:
int f(vector<vector<int>> &triangle,int i,int j,vector<vector<int>> &dp){
    if(i == triangle.size()){
        return 0;
    }
    if(j >= i+1){
        return INT_MAX;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] =  min(f(triangle,i+1,j,dp),f(triangle,i+1,j+1,dp)) + triangle[i][j];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        // int i = 0;
        // int j = 0;
        // vector<vector<int>> dp(triangle.size()+1,vector<int>(triangle.size()+1,0));
        vector<int> prev(triangle.size()+1,0);
        vector<int> curr(triangle.size()+1,0);
        // return f(triangle,i,j,dp);  // Solved Using Recursion 
        for(int i = 0;i<triangle.size();i++){
            for(int j = i+1;j<=triangle.size();j++){
                prev[j] = INT_MAX;
            }
        }

        for(int i = triangle.size()-1;i>=0;i--){
            for(int j = i;j>=0;j--){
                prev[j] =  min(curr[j],curr[j+1]) + triangle[i][j];
            }
            curr = prev;
        }

        return curr[0];
    }
};
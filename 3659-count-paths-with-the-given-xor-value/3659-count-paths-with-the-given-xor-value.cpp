class Solution {
public:
int M = 1e9 +7;
int dp[300][300][16];
int f(int i,int j,vector<vector<int>>& grid,int &k,int xr){
    if(i == grid.size()-1 && j == grid[0].size()-1){
        if(xr == k){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][j][xr]!= -1){
        return dp[i][j][xr];
    }
    int ans = 0 ;
    if(i+1 < grid.size()){
       ans += f(i+1,j,grid,k,(xr^grid[i+1][j]));
    }
    if(j+1 < grid[0].size()){
       ans += f(i,j+1,grid,k,(xr^grid[i][j+1]));
    }

    return dp[i][j][xr] =  ans%M;
}
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,grid,k,grid[0][0]);
    }
};
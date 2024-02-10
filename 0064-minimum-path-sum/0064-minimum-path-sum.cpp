class Solution {
public:
int f(vector<vector<int>> &grid,int x,int y,vector<vector<int>> &dp){
    if(x == grid.size()-1 && y == grid[0].size()-1){
        return grid[grid.size()-1][grid[0].size()-1];
    }
    if(x>=grid.size() || y>=grid[0].size()){
        return 10e8;
    }
    if(dp[x][y] != -1){
        return  dp[x][y];
    }

    int left = grid[x][y] + f(grid,x,y+1,dp);
    int bot = grid[x][y] + f(grid,x+1,y,dp);

    return dp[x][y] = min(left,bot);
}
    int minPathSum(vector<vector<int>>& grid) {
        int i = 0,j = 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return f(grid,i,j,dp);
    }
};
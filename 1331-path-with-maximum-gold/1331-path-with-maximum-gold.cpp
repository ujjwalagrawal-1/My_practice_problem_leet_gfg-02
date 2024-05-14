class Solution {
public:
int solve(vector<vector<int>> grid,int  i,int j){
    int n = grid.size(),m = grid[0].size();
    if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0){
        return 0;
    }
    vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
    int count = grid[i][j];
    int ans = count;
    grid[i][j] = 0;

    for(int k = 0;k<dir.size();k++){
        ans =  max(ans,solve(grid,i+dir[k][0],j+dir[k][1]) + count);
    }
    grid[i][j] = count;

    return   ans;
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int i = 0,j = 0;
        int maxi = 0 ;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                // vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
                maxi = max(maxi,solve(grid,i,j));
            }
        }
        return maxi;
    }
};
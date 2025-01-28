class Solution {
public:
int dfs(int i,int j,vector<vector<int>> &grid){
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    int ans = grid[i][j];
    grid[i][j] = 0;
    for(int k = 0;k<4;k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < grid.size() &&  nx >=0 && ny < grid[0].size() && ny >= 0 && grid[nx][ny] > 0){
            ans += dfs(nx,ny,grid);
        }
    }
    return ans;
}
    int findMaxFish(vector<vector<int>>& grid) {
        // vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int maxi = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j =  0 ;j<grid[0].size();j++){
                if( grid[i][j] > 0){
                    maxi = max(maxi,dfs(i,j,grid));
                }
            }
        }
        return maxi;
    }
};
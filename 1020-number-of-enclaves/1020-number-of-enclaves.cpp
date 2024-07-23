class Solution {
public:
int delrow[4] = {-1,0,1,0};
int delcol[4] = {0,1,0,-1};
void dfs(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &visited){
    visited[x][y] = 1;
    for(int i = 0;i<4;i++){
        int n = grid.size();
        int m = grid[0].size();
        int nrow = x  + delrow[i];
        int ncol = y + delcol[i];

        if(nrow < n  && ncol < m && nrow >= 0 && ncol>= 0){
            if(grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                dfs(nrow,ncol,grid,visited);
            }
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            if(grid[i][0] == 1 && !visited[i][0]){
                dfs(i,0,grid,visited);
            }
            if(grid[i][m-1] == 1 && !visited[i][m-1]){
                dfs(i,m-1,grid,visited);
            }
        }
        for(int i = 0;i<m;i++){
            if(grid[0][i] == 1 && !visited[0][i]){
                dfs(0,i,grid,visited);
            }
            if(grid[n-1][i] == 1 && !visited[n-1][i]){
                dfs(n-1,i,grid,visited);
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
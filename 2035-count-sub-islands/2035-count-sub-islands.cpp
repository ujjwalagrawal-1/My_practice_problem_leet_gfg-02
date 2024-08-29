class Solution {
public:
bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j){
    // visited[i][j] = 1;

    if(i >= grid1.size() || i < 0 || j  >= grid1[0].size() || j < 0 || !grid2[i][j])return true;
    if(!grid1[i][j]){
        return false;
    }
    grid2[i][j] = 0;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};
    bool ans = 1;
    for(int k = 0;k<4;k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        ans &= dfs(grid1,grid2,nx,ny);
    }
    return ans;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        for(int i = 0;i<grid1.size();i++){
            for(int j = 0;j<grid1[0].size();j++){
                if(grid2[i][j]){
                    if(dfs(grid1,grid2,i,j)){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};
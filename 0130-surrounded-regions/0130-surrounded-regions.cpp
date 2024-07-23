class Solution {
public:
int delrow[4] = {-1,0,1,0};
int delcol[4] = {0,1,0,-1};
void dfs(int x,int y,vector<vector<int>> &visited,vector<vector<char>> &board){
    visited[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int nrow = x + delrow[i];
        int ncol = y + delcol[i];
        if(nrow < board.size() && ncol < board[0].size() && nrow >= 0 && ncol >= 0){
            if(board[nrow][ncol] == 'O' && visited[nrow][ncol] == 0){
                dfs(nrow,ncol,visited,board);
            }
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n = board.size();int m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            if(board[i][0] == 'O' && !visited[i][0]){
                dfs(i,0,visited,board);
            }   
            if(board[i][m-1] == 'O' && !visited[i][m-1]){
                dfs(i,m-1,visited,board);
            }
        }
        for(int i = 0;i<m;i++){
            if(board[0][i] == 'O' && !visited[0][i]){
                dfs(0,i,visited,board);
            }
            if(board[n-1][i] == 'O' && !visited[n-1][i]){
                dfs(n-1,i,visited,board);
            }
        }

        for(int i = 1;i<n-1;i++){
            for(int j = 1;j<m-1;j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }   
            }
        }
    }
};
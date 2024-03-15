class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int side = 0;
        vector<vector<int>> row = grid, col = grid;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
              if(grid[i][j] == 1) { 
                row[i][j] = (j > 0) ? 1 + row[i][j-1] : 1;
                col[i][j] = (i > 0) ? 1 + col[i-1][j] : 1;
              }
              else { 
                row[i][j] = 0;
                col[i][j] = 0;
              }
            }
        }
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                int limit = min(row[i][j],col[i][j]);
                for(int mini=1; mini<=limit; mini++) {
                    if(i-(mini-1) >= 0 && j-(mini-1) >= 0 && row[i-(mini-1)][j] >= mini && col[i][j-(mini-1)] >= mini) {
                        side = max(side,mini);
                    }
                }
            }
        }
     return side*side;
    }
};
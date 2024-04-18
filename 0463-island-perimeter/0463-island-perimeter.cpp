class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int perimeter = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                perimeter += getEdges(grid, r, c);
            }
        }
        return perimeter;
    }
private:
    int getEdges(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] == 0) return 0;
        int row = grid.size(), col = grid[0].size();
        int edge = 0;
        if ((r == 0) || (grid[r - 1][c] == 0)) edge++;
        if ((r == (row - 1)) || (grid[r + 1][c] == 0)) edge++;
        if ((c == 0) || (grid[r][c - 1] == 0)) edge++;
        if ((c == (col - 1)) || (grid[r][c + 1] == 0)) edge++;
        return edge;
    }
};
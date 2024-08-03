class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size()/2; i++) {
            for (int j = 0; j < (grid[0].size()) / 2; j++) {
                if (grid[i][j] != grid[i][grid[0].size() - j - 1]) {
                    cnt++;
                }
            }
        }
        for (int i = 0; i < grid[0].size()/2; i++) {
            for (int j = 0; j < (grid.size()) / 2; j++) {
                if (grid[j][i] != grid[grid.size()-1-j][i]) {
                   cnt++;
                }
            }
        }
        return cnt;
    }
};

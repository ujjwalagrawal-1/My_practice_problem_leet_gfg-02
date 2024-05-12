class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        vector<vector<int>> ans(grid.size()-2,vector<int>(grid[0].size() - 2));
        for(int i = 0;i<grid[0].size()-2;i++){
            for(int j = 0;j<grid[0].size()-2;j++){
            int maxi = INT_MIN;
               for(int k = i;k<i+3;k++){
                for(int l = j;l<j+3;l++){
                    maxi = max(maxi,grid[k][l]);
               }
               }
               ans[i][j] = maxi;
            }
        }
        return ans;
    }
};
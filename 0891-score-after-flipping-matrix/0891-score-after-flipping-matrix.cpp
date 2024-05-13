class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        vector<int> veci(grid.size());
        for(int i = 0;i<grid.size();i++){
            int a = 0;
            int b = 0;
            int h = 0;
            for(int j = grid[0].size()-1;j>=0;j--){
                if(grid[i][h] == 0){
                    b += pow(2,j);
                }
                else{
                    a += pow(2,j);
                }
                h++;
            }
            if(b > a){
                for(int j = 0;j<grid[0].size();j++){
                    grid[i][j] = grid[i][j] == 0 ? 1 : 0;
                }
            }
        }
        int ans = 0;int h = 0;
        for(int i = grid[0].size()-1;i>=0;i--){
            int a = 0;
            for(int j = 0;j<grid.size();j++){
                if(grid[j][h] == 0){
                    a++;
                }
            }
            int b = grid.size() - a;
            b = max(b,a);
            ans += pow(2,i)*b;
            h++;
        }
        return ans;
    }
};
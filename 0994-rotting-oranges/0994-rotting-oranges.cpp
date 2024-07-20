#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> qu;
        int freshOranges = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    qu.push({i,j});
                }
                if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }


        if(freshOranges == 0) return 0;

        int mov[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        int cnt = 0;

        while(!qu.empty()){
            int sz = qu.size();
            bool progress = false;

            for(int i = 0; i < sz; i++){
                int x = qu.front().first;
                int y = qu.front().second;
                qu.pop();
                for(int j = 0; j < 4; j++){
                    int rx = x + mov[j][0];
                    int ry = y + mov[j][1];
                    if(rx < 0 || rx >= n || ry < 0 || ry >= m || grid[rx][ry] != 1) continue;
                    grid[rx][ry] = 2;
                    qu.push({rx, ry});
                    freshOranges--;
                    progress = true;
                }
            }

            if(progress) cnt++;
        }

        return freshOranges == 0 ? cnt : -1;
    }
};

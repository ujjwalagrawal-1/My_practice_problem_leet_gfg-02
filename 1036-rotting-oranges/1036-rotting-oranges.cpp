class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        int t = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    qu.push({i,j});
                }
                if(grid[i][j] == 1)t++;
            }
        }
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {1, 0 , -1 , 0};
        int dy[4] = {0, -1, 0, 1};
        int min = 0;
        while(!qu.empty()){
            int w = qu.size();
            bool fl = 0;
            for(int i = 0;i<w;i++){
                auto node = qu.front();
                qu.pop();
                int x = node.first;
                int y = node.second;
                for(int j = 0;j<4;j++){
                    if(x+dx[j] < n && x+dx[j] >= 0 && y + dy[j] < m && y + dy[j] >= 0 && grid[x+dx[j]][y+dy[j]] == 1){
                        t--;
                        grid[x + dx[j]][y+dy[j]] = 2;
                        fl = 1;
                        qu.push({x+dx[j],y + dy[j]});
                    }
                }
            }
            if(fl)min++;
        }
        return t > 0 ? -1 : min;
    }
};
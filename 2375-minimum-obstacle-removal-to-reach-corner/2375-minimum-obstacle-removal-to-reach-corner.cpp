// class Solution {
// public:
// int f(vector<vector<int>> &grid,int i ,int j){
//     if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
//         return INT_MAX;
//     }
//     if(i == 0 && j == 0){
//         return 0;
//     }
//     int mini = 0;
//     if(grid[i][j] == 1){
//         mini = min({f(grid,i-1,j),f(grid,i+1,j),f(grid,i,j-1),f(grid,i,j+1)})+1;
//     }
//     else{
//         mini = min({f(grid,i-1,j),f(grid,i+1,j),f(grid,i,j-1),f(grid,i,j+1)});
//     }

//     return mini;
// }
//     int minimumObstacles(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         return f(grid,n-1,m-1);
//     }
// };

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // queue<pair<int,int>> qu;
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{n-1,m-1}});
        int disx[4] = {0,-1,0,1};
        int disy[4] = {1,0,-1,0};
        while(!pq.empty()){
            int wei = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int i = 0;i<4;i++){
                int ndx = x + disx[i];
                int ndy = y + disy[i];
                int w = 0;
                if(ndx >= 0 && ndy >= 0 && ndx  < n && ndy < m){
                    if(grid[ndx][ndy] == 1){
                        w = 1;
                    }
                    if(wei + w < dis[ndx][ndy]){
                        dis[ndx][ndy] = wei + w;
                        pq.push({wei + w,{ndx,ndy}});
                    }
                }
            }
        }
        return dis[0][0];
    }
};
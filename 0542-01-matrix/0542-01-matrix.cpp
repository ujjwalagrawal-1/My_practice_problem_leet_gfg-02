class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));


        queue<pair<pair<int,int>,int>> qu;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    qu.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        while(!qu.empty()){
            int x = qu.front().first.first;
            int y = qu.front().first.second;
            int t = qu.front().second;
            qu.pop();

            mat[x][y] = t;
            int delrow[] = {-1, 0, +1, 0}; 
	        int delcol[] = {0, +1, 0, -1}; 

            for(int i = 0;i<4;i++) {
	            int nrow = x + delrow[i]; 
	            int ncol = y + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                qu.push({{nrow, ncol}, t+1});  
	            }
	        }
        }
        return mat;
    }
};
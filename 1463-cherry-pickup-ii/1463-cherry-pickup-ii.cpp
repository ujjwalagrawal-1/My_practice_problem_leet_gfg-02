class Solution {
public:
int f(int i1,int j1,int j2,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
    
    if(j1<0 || j2<0 || j1>=c || j2>=c){ 
        return -10e8;
    }
    if(i1 == grid.size()-1){
        if(j1 == j2){
            return grid[i1][j1];
        }
        else{
            return grid[i1][j1] + grid[i1][j2];
        }
    }
    if(dp[i1][j1][j2] != -1){
        return dp[i1][j1][j2];
    }
    int maxi = -10e8;
    for(int i = -1;i<=1;i++){
        for(int j = -1;j<=1;j++){
            int val = 0;
            if(j1 == j2){
                val = grid[i1][j1];
            }
            else{
                val = grid[i1][j1] +grid[i1][j2];
            }
            val +=  f(i1+1,j1+i,j2+j,c,grid,dp);

            maxi = max(maxi,val);
        }
    }
    return dp[i1][j1][j2] =  maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int c = grid[0].size();
        int r = grid.size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return f(0,0,c-1,c,grid,dp);
    }
};
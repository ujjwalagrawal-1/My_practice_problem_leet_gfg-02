class Solution {
public:
    int rec( int r1 , int c1 , int c2 , vector<vector<int>> &grid , vector<vector<vector<int>>> &dp )
    {   int r2 = r1 + c1 - c2;
        if( r1<0 || r2<0 || c1 <0 || c2 < 0 || grid[r1][c1]==-1 || grid[r2][c2] == -1 ) return -1e8;
        if(r1==0 && c1==0 && c2==0) return grid[r1][c1];
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        int comb1 = rec(r1,c1-1,c2-1,grid,dp);
        int comb2 = rec(r1,c1-1,c2,grid,dp) ;
        int comb3 = rec(r1-1,c1,c2-1,grid,dp);
        int comb4 = rec(r1-1,c1,c2,grid,dp) ;
        int maxcomb = max(max(comb1,comb2),max(comb3,comb4));
        int gridcost = ( c1!=c2 ?   grid[r1][c1]+grid[r2][c2] : grid[r1][c1]);

        return dp[r1][c1][c2]  = maxcomb + gridcost; // return maximum combintation 
    }

    int cherryPickup(vector<vector<int>>& grid) {
          int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n, vector<int> (n,-1)));
        int ans = rec(n-1,n-1,n-1,grid,dp);
        
        if( ans < 0 ) return 0;
        else return ans;
        
    }
};
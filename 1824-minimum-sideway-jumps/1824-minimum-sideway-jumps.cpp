class Solution {
public:
int f(vector<int>&br,int i,int j,vector<vector<int>> &dp){
    if(j >= br.size()-1){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(br[j+1] == i){
        int k  = INT_MAX,l = INT_MAX;
        if(i == 1){
            if(br[j] != 2){
                k = f(br,2,j,dp);
            }
            if(br[j] != 3){
                l = f(br,3,j,dp);
            }
        }
        else if(i == 2){
            if(br[j] != 1){
                k = f(br,1,j,dp);
            }
            if(br[j] != 3){
                l = f(br,3,j,dp);
            }
        }
        else{
            if(br[j] != 2){
                k = f(br,2,j,dp);
            }
            if(br[j] != 1){
                l = f(br,1,j,dp);
            }
        }
        return dp[i][j] =  min(k,l)+1;
    }

    else {
        return dp[i][j]  = f(br,i,j+1,dp);
    }
}
    int minSideJumps(vector<int>& br) {
        // solve using recursion
        vector<vector<int>> dp(4,vector<int>(br.size(),-1));
        int mini = f(br,2,0,dp);
        return mini;
    }
};
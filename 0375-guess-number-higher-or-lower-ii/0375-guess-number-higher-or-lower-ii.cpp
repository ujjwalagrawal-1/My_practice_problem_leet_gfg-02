class Solution {
public:

//Full Recursive Solution
int Solve_Using_Recurson(int start,int end){
    if(start>=end){
        return 0;
    }

    int ans = INT_MAX;
    for(int i = start;i<=end;i++){
        ans = min(ans,i + max(Solve_Using_Recurson(start,i-1),Solve_Using_Recurson(i+1,end)));
    }

    return ans;
}

//Optimising into Memoisation
int Solve_Using_Memoisation(int start,int end,vector<vector<int>> &dp){
    if(start >= end){
        return 0;
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }
    int ans = INT_MAX;
    for(int i = start;i<=end;i++){
        ans = min(ans,i + max(Solve_Using_Memoisation(start,i-1,dp),Solve_Using_Memoisation(i+1,end,dp)));
    }

    return dp[start][end] = ans;
}
    int getMoneyAmount(int n) {
        //Forming the recursive relation
        // return Solve_Using_Recurson(1,n);

        //Memoisation 
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return Solve_Using_Memoisation(1,n,dp);
    }
};
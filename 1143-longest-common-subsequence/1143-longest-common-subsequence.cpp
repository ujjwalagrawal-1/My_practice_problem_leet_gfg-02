class Solution {
public:

// Recursive Approch
int solve_using_recursion(string &text1,string &text2,int i,int j){
    if(i == text1.size()){
        return 0;
    }
    if(j == text2.size()){
        return 0;
    }
    int ans = 0;
    if(text1[i] == text2[j]){
        ans = solve_using_recursion(text1,text2,i+1,j+1) + 1;
    }
    else{
        ans = max(solve_using_recursion(text1,text2,i+1,j),solve_using_recursion(text1,text2,i,j+1));
    }
    return ans;
}

// solving_using_memoisation;
int solve_using_Memoisation(string &text1,string &text2,int i,int j,vector<vector<int>> &dp){
    if(i == text1.size()){
        return 0;
    }
    if(j == text2.size()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = 0;
    if(text1[i] == text2[j]){
        ans = solve_using_Memoisation(text1,text2,i+1,j+1,dp) + 1;
    }
    else{
        ans = max(solve_using_Memoisation(text1,text2,i+1,j,dp),solve_using_Memoisation(text1,text2,i,j+1,dp));
    }
    return dp[i][j] = ans;

}
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // return solve_using_recursion(text1,text2,i,j);


        // solving_using_memoisation
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve_using_Memoisation(text1,text2,i,j,dp);
    }
};
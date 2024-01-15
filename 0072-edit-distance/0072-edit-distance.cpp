class Solution {
public:
    int solve_using_recursion(string &word1, string &word2, int index, int index2, vector<vector<int>> &dp) {
        if (index < 0) {
            if (index2 < 0){
                return 0;
            }
            else{
                return index2+1;
            }
        }
        if(index2 < 0){
            return index+1;
        }
        if(dp[index][index2] != -1){
            return dp[index][index2];
        }
        int mini = INT_MAX;
        // replace
        int a = solve_using_recursion(word1, word2, index - 1, index2 - 1,dp) + 1;
        // delete
        int b = solve_using_recursion(word1, word2, index - 1, index2,dp) + 1;
        int d = solve_using_recursion(word1, word2, index, index2 - 1,dp) + 1;
        int c = 10e8;  // Initialize c to a large value
        if (index2 >= 0 && word1[index] == word2[index2]) {
            c = solve_using_recursion(word1, word2, index - 1, index2 - 1,dp);
        }
        mini = min({a, b, c, d});
        return dp[index][index2] = mini;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int> (word2.size()+1,-1));
        return solve_using_recursion(word1, word2, word1.size() - 1, word2.size() - 1,dp);
    }
};

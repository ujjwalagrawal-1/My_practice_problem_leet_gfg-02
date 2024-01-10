class Solution {
public:
int solve_using_rec(vector<int> & arr,map<pair<int,int>,int> &ump,int left,int right,vector<vector<int>> &dp){
    // base condition
    if(left == right){
        return 0;
    }
    if(dp[left][right] != -1){
        return dp[left][right];
    }
    //main function
    int mini = INT_MAX;
    for(int i = left;i<right;i++){
        mini = min(mini,ump[{left,i}]*ump[{i+1,right}] + solve_using_rec(arr,ump,left,i,dp) + solve_using_rec(arr,ump,i+1,right,dp));
    }

    dp[left][right] = mini;
    return dp[left][right];
}

//By tabulation method
int solving_using_tabulation(vector<int> & arr,map<pair<int,int>,int> &ump){
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    // int n = arr.size();

    for(int left = n-1;left >= 0;left--){
        for(int right = 0;right <= n-1;right++){
            if(left == right){
                continue;
            }
            else{

            
            int mini = INT_MAX;
        for(int i = left;i<right;i++){
        mini = min(mini,ump[{left,i}]*ump[{i+1,right}] + dp[left][i] + dp[i+1][right]);
           }    

        dp[left][right] = mini;
        }
        }
    }
    return dp[0][n-1];
}
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> ump;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            ump[{i,i}] = arr[i];
            for(int j = i+1;j<n;j++){
                ump[{i,j}] = max(ump[{i,j-1}],arr[j]);
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solve_using_rec(arr,ump,0,arr.size()-1,dp);


        return solving_using_tabulation(arr,ump);
    }
};
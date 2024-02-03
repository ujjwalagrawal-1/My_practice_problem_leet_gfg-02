class Solution {
public:
    int f(vector<int>& arr, int k, int ind, int n, vector<int>& dp) {
        if (ind >= arr.size()) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int maxi = INT_MIN;
        int maxb = INT_MIN;
        int len = 0;
        for (int i = ind; i < min(ind + k, n); i++) {
            maxb = max(maxb, arr[i]);
            len++;
            int sum = (maxb * len) + f(arr, k, i + 1, n, dp);
            maxi = max(maxi, sum);
        }
        return dp[ind] = maxi;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, 0);int n = arr.size();
        // return f(arr, k, 0, arr.size(), dp); solved using Memoisation
        for(int ind = n-1;ind >= 0;ind--){
        int maxi = INT_MIN;
        int maxb = INT_MIN;
        int len = 0;
        for (int i = ind; i < min(ind + k, n); i++) {
            maxb = max(maxb, arr[i]);
            len++;
            int sum = (maxb * len) + dp[i + 1];
            maxi = max(maxi, sum);
        }
        dp[ind] = maxi;
        }
        return dp[0];
    }
};

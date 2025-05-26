class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // I don't have to take the Cycled Path 
        // I only have to take the path from 0 - leaf nodes and check the maximum ocuuring color for each path from root node to leaf node.
        // can we find  the nodes which are not a part of the cycle and traverse until that point if reached the leaf node then 
        set<int> st;
        int n = colors.size();
        vector<int> ind(n);
        vector<vector<int>> adj(n);
        for(auto itr : edges){
            adj[itr[0]].push_back(itr[1]);
            ind[itr[1]]++;
        }
        // cout<<"yes "<<endl;
        queue<int> qe;
        vector<vector<int>> dp(n,vector<int>(26,0));
        for(int i = 0;i<n;i++){
            if(ind[i] == 0){
                dp[i][colors[i] - 'a'] = 1;
                qe.push(i);
            }
        }
        int ans = 0;
        while(!qe.empty()){
            int node = qe.front();
            qe.pop(); 
            bool fl = 0;
            for(auto itr : adj[node]){
                for(int i = 0;i<26;i++){
                    dp[itr][i] = max(dp[itr][i],dp[node][i] + ((colors[itr] - 'a') == i ? 1 : 0));
                }
                ind[itr]--;
                if(ind[itr] == 0){
                    qe.push(itr);
                    fl = 1;
                }
            }
            if(!fl){
                for(int i = 0;i<dp[node].size();i++){
                    ans = max(ans,dp[node][i]);
                }
            }
        }
        for(int i = 0; i < n; ++i){
            if(ind[i] > 0)
                return -1;
        }
        return ans;
    }
};
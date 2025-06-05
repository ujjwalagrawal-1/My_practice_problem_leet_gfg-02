class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> depth(n, -1);
        int maxLen = -1;
        function<void(int, int)> dfs = [&](int node, int d){
            vis[node] = 1;
            depth[node] = d;
            int next = edges[node];
            if (next != -1) {
                if (!vis[next]) {
                    dfs(next, d + 1);
                }
                else if (depth[next] != -1) {
                    maxLen = max(maxLen, d - depth[next] + 1);
                }
            }
            depth[node] = -1;
        };
        for(int i = 0; i < n; ++i){
            if (!vis[i]){
                dfs(i, 0);
            }
        }
        return maxLen;
    }
};

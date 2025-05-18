class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlis(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjlis[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        function<void(int)> dfs = [&](int node){
            vis[node] = 1;
            for (int neighbor : adjlis[node]) {
                if (!vis[neighbor]) {
                    dfs(neighbor);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i);
            }
        }

        return cnt;
    }
};

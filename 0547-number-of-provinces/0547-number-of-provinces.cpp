class Solution {
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adjlis) {
        visited[node] = 1;
        for (auto itr : adjlis[node]) {
            if (!visited[itr]) {
                dfs(itr, visited, adjlis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlis(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjlis[i].push_back(j);
                    adjlis[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, visited, adjlis);
            }
        }

        return cnt;
    }
};

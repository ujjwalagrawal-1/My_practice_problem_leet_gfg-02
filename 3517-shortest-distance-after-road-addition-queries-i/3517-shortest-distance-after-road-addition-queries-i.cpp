class Solution {
public:
    int bfs(const vector<vector<int>>& graph, int n) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[n - 1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            graph[u].push_back(v);
            answer.push_back(bfs(graph, n));
        }

        return answer;
    }
};
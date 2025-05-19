class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0], v = edges[i][1];
            double prob = sp[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        vector<double> ans(n,0.00);
        ans[start_node] = 1.00;
        priority_queue<pair<double,int>> pq;
        pq.push({1.00,start_node});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            for(auto itr : adj[node.second]){
                if(double(node.first*itr.second) > ans[itr.first]){
                    ans[itr.first] = node.first*itr.second;
                    pq.push({ans[itr.first],itr.first});
                }
            }
        }
        return ans[end_node];
    }
};
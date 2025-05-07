typedef long long ll;

class Solution {
public:
    pair<ll,ll> f(vector<vector<ll>> &adj, vector<ll> &vis, ll node,vector<int> &values) {
        vis[node] = 1;
        ll sum = 0;
        ll pass = 0;
        ll leaf = 0;
        for(auto itr : adj[node]) {
            if(!vis[itr]) {
                leaf = 1;
                auto a = f(adj, vis, itr,values);
                sum += a.first;
                pass += a.second;
            }
        }

        if(!leaf) {
            return {values[node]*1ll,values[node]*1ll};
        }
        return {sum + values[node]*1ll,min(values[node]*1ll,pass)};
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<ll>> adj(n);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<ll> vis(n);
        pair<ll,ll> ans = f(adj, vis, 0,values);
        // cout<<ans.first<<" "<<ans.second<<endl;
        return ans.first - ans.second;
    }
};

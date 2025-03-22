typedef  long long ll;
class Solution {
public:
vector<int> vis;
void dfs(vector<int> adj[],set<ll> &st,int node){
    vis[node] = 1;
    st.insert(node);
    for(auto itr : adj[node]){
        if(!vis[itr]){
            dfs(adj,st,itr);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto itr : edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        vis.resize(n,0);
        int cnt = 0;
        
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                set<ll> st;
                dfs(adj,st,i);
                bool fl = 1;
                for(auto itr : st){
                    if(adj[itr].size() != st.size()-1){
                        fl = 0;
                        break;
                    }
                }
                if(fl)cnt++;
            }
        }
        return cnt;
    }
};
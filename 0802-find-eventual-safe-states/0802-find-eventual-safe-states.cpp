class Solution {
public:
bool dfs(int node,vector<int> &vis,vector<int> &pathvis,vector<int> &check,vector<vector<int>> &graph){
    vis[node] = 1;
    pathvis[node] = 1;
    check[node] = 0;
    for(auto itr : graph[node]){
        if(!vis[itr]){
            if(dfs(itr,vis,pathvis,check,graph) == true){
                return true;
            }
        }
        else if(pathvis[itr]){
            return true;
        }
    }

    check[node] = 1;
    pathvis[node] = 0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size());
        vector<int> pathvis(graph.size());
        vector<int> check(graph.size());
        vector<int> ans;
        for(int i = 0;i<graph.size();i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,check,graph);
            }
        }

        for(int i = 0;i<check.size();i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
class Solution {
public:
bool dfs(int i,vector<vector<int>> &graph,vector<int> &color,int col){
    color[i] = col;
    for(auto itr : graph[i]){
        if(color[itr] == -1){
         if(!dfs(itr,graph,color,!col)){
            return false;
         }
        }
        else if(color[itr] == color[i]){
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        // Using DFS
        vector<int> color(graph.size(),-1);
        for(int i = 0;i<color.size();i++){
            if(color[i]  == -1){
                if(!dfs(i,graph,color,0)){
                    return false;
                }
            }
        }
        return true;
    }
};
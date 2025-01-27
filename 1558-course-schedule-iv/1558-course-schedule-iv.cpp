class Solution {
public:
void dfs(vector<int>& vis,int start,int end,vector<vector<int>> &adj,set<pair<int,int>> &st){
    vis[end] = 1;
    st.insert({start,end});
    for(auto itr : adj[end]){
        if(!vis[itr]){
            dfs(vis,start,itr,adj,st);
        }
    }
}
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prer, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0;i<prer.size();i++){
            adj[prer[i][0]].push_back(prer[i][1]);
        }
        set<pair<int,int>> st;

        for(int i = 0;i<numCourses;i++){
            vector<int> vis(numCourses,0);
            dfs(vis,i,i,adj,st);
        }

        vector<bool> ans;
        for(auto itr : queries){
            if(st.count({itr[0],itr[1]})){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
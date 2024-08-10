class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> adj[quiet.size()];
        vector<int> indegree(quiet.size(),0);

        for(auto itr:richer){
            adj[itr[0]].push_back(itr[1]);
            indegree[itr[1]]++;
        }
        queue<int> qu;
        vector<int> ans(quiet.size());
        for(int i = 0;i<quiet.size();i++){
            ans[i] = i;
        }
        for(int i = 0;i<quiet.size();i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            for(auto itr : adj[node]){
                if(quiet[ans[node]]<quiet[ans[itr]])
                {
                    ans[itr]=ans[node];
                }
                indegree[itr]--;
                if(indegree[itr] == 0){
                    qu.push(itr);
                }
            }
        }
        return ans;
    }
};
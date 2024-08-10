class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& pr) {
        // Normal TopoSort Question 
        vector<int> ans;
        vector<int> adj[nc];
        vector<int> indegree(nc); 
        for(auto itr : pr){
            adj[itr[1]].push_back(itr[0]);
            indegree[itr[0]]++;
        }
        queue<int> q;
        for(int i = 0;i<nc;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto itr : adj[node]){
                indegree[itr]--;
                if(indegree[itr] == 0){
                    q.push(itr);
                }
            }
        }
        if(ans.size() != nc){
            return {};
        }
        return ans;
        
    }
};
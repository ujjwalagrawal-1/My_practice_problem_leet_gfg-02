class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pr) {
        // calculating indegree first 
        vector<vector<int>> adj(nc);
        vector<int> id(nc,0);
        for(int i = 0;i<pr.size();i++){
            id[pr[i][1]]++;
            adj[pr[i][0]].push_back(pr[i][1]);
        }
        int ans = 0;
        queue<int> qu;
        for(int i = 0;i<nc;i++){
            if(id[i] == 0){
                qu.push(i);
                ans++;
            }
        }
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            for(auto itr : adj[node]){
                id[itr]--;
                if(id[itr] == 0){
                    qu.push(itr);
                    ans++;
                }
            }
        }
        if(ans == nc){
            return 1;
        }
        else{
            return 0;
        }
    }
};
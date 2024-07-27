class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i = 0;i<f.size();i++){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }

        queue<pair<int,pair<int,int>>> pq;

        vector<int> dis(n,1e9);

        dis[src] = 0;

        pq.push({0,{0,src}});

        while(!pq.empty()){
            int stop = pq.front().first;
            int cdis = pq.front().second.second;
            int node = pq.front().second.first;
            pq.pop();
            for(auto itr : adj[node]){
                int cost = itr.second;
                int adjnode = itr.first;
                if(stop > k){
                    continue;
                }
                if(cost + cdis < dis[adjnode] && stop <= k){
                    dis[adjnode] = cost + cdis;
                    pq.push({stop + 1,{adjnode,dis[adjnode]}});
                }
            }
        }
        if(dis[dst] == 1e9)return -1;
        else return dis[dst];
    }
};
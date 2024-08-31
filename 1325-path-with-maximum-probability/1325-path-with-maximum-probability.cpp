class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<double,double>> adj[n];

        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> arr(n+1,0);
        arr[start_node] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});

        while(!pq.empty()){
            double wgt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto itr : adj[node]){
                if(wgt*itr.second > arr[itr.first]){
                    arr[itr.first] = wgt*itr.second;
                    pq.push({arr[itr.first],itr.first});
                }
            }
        }
        return arr[end_node];
    }
};
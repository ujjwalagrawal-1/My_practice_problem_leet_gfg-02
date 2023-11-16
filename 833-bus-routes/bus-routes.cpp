class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = size(routes);
        unordered_map<int, vector<int>> m;

        for(int i = 0; i < n; i++) {
            int BusId = i;
            vector<int> BusStops = routes[i];
            for(auto &BusStop : BusStops) {
                m[BusStop].push_back(BusId);
            }
        }

        queue<pair<int, int>> q;
        unordered_map<int, bool> BS_vis, BId_vis;
        q.push({source, 0});
        BS_vis[source] = true;

        while(!q.empty()) {
            int currBS = q.front().first, currBTravelled = q.front().second;
            q.pop();

            if(currBS == target) return currBTravelled;

            vector<int> BusIds = m[currBS];
            for(auto &BusId : BusIds) {
                if(BId_vis.find(BusId) == BId_vis.end()) {

                    for(auto &BusStop : routes[BusId]) {
                        if(BS_vis.find(BusStop) == BS_vis.end()) {
                            q.push({BusStop, currBTravelled + 1});
                            BS_vis[BusStop] = true;
                        }
                    }   

                    BId_vis[BusId] = true;
                }
            }
        }

        return -1;
    }
};
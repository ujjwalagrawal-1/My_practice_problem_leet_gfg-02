typedef long long ll;
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        ll sum = 0;
        priority_queue<pair<ll, ll>> pq;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                pq.push({grid[i][j] , i});
            }
        }
        while(k){
            auto y = pq.top();
            pq.pop();
            if(limits[y.second]){
                sum += y.first;
                limits[y.second]--;
                k--;
            }
        }
        return sum;
    }
};
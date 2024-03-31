class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size(), mini = INT_MAX;
        multiset<int> s1, s2;
        for(int i = 0 ; i < n ; i++){
            int x = points[i][0], y = points[i][1];
            s1.insert(x + y);
            s2.insert(x - y);
        }
        for(int i = 0 ; i < n ; i++){
            int x = points[i][0], y = points[i][1];
            s1.erase(s1.find(x + y));
            s2.erase(s2.find(x - y));
            int maxi = max(*s1.rbegin() - *s1.begin(), *s2.rbegin() - *s2.begin());
            mini = min(mini, maxi);
            s1.insert(x + y);
            s2.insert(x - y);
        }
        return mini;
    }
};
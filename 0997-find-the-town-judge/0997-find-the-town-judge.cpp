class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1)
            return 1;

        unordered_map<int, int> mp;

        for (auto v : trust)
        {
            mp[v[0]] = -1;
            if (mp[v[1]] != -1)
                mp[v[1]]++;
        }

        for (auto it : mp)
        {
            if (it.second == n-1)
                return it.first;
        }

        return -1;
    }
};
class Solution {
public:
    static bool comp(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (const auto& word : words) {
            mp[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(&comp)> pq(comp);

        for (const auto& itr : mp) {
            pq.push({itr.second, itr.first});
            if (pq.size() > k) {
                // cout<<
                pq.pop();
            }
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};

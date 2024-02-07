
class Solution {
public:
    static bool mycomp(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        vector<pair<char, int>> veci;
        for (auto itr : mp) {
            veci.push_back(itr);
        }
        s = "";
        sort(veci.begin(), veci.end(), mycomp);
        for (auto itr : veci) {
            for (int i = 0; i < itr.second; i++) {
                s += itr.first;
            }
        }
        return s;
    }
};
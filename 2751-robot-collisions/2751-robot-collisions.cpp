class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hlt, string dir) {
        map<int, pair<int, pair<int, char>>> mp;
        for (int i = 0; i < pos.size(); i++) {
            mp[pos[i]] = {hlt[i], {i, dir[i]}};
        }
        stack<pair<int, pair<int, char>>> st;
        for (auto itr : mp) {
            while (!st.empty() && st.top().second.second == 'R' && itr.second.second.second == 'L') {
                if (st.top().first == itr.second.first) {
                    st.pop();
                    itr.second.first = 0;
                    break;
                } else if (st.top().first > itr.second.first) {
                    st.top().first--;
                    itr.second.first = 0;
                    break;
                } else {
                    itr.second.first--;
                    st.pop();
                }
            }

            if (itr.second.first > 0) {
                st.push(itr.second);
            }
        }

        vector<pair<int, int>> veci;
        while (!st.empty()) {
            veci.push_back({st.top().second.first, st.top().first});
            st.pop();
        }

        sort(veci.begin(),veci.end());
        vector<int> ans;
        for (auto itr : veci) {
            ans.push_back(itr.second);
        }
        return ans;
    }
};

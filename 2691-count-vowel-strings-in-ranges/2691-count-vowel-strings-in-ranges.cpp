class Solution {
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        vector<int> ans(w.size());
        vector<int> temp;
         auto chk = [](char a) -> bool {
            return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
        };
        for (int i = 0; i < w.size(); i++) {
            ans[i] = chk(w[i].front()) && chk(w[i].back()) ? 1 : 0;
            if (i > 0) {
                ans[i] += ans[i - 1];
            }
        }
        for(auto& itr : q){
            int r = ans[itr[1]] -(itr[0] > 0 ? ans[itr[0]-1] : 0);
            temp.push_back(r);
        }

        return temp;
    }
};
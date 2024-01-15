class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> s;
        map<int,int> mp;
        for(int i = 0;i<matches.size();i++){
            mp[matches[i][1]]++;
            s.insert(matches[i][0]);
        }
        vector<int> b;
        vector<int> a;
        for(auto itr:mp){
            if(itr.second >= 1){
            if(s.find(itr.first) != s.end()){
                s.erase(itr.first);
            }
            }
            if(itr.second == 1){
                b.push_back(itr.first);
            }
        }
        for(auto itr:s){
            a.push_back(itr);
        }
        vector<vector<int>> ans(2);
        ans[0] = (a);
        ans[1]= (b);
        return ans;


    }
};
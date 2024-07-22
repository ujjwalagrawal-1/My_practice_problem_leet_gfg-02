class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mp;
        for(int i =0;i<names.size();i++){
            mp[heights[i]] = names[i];
        }
        vector<string> ans;
        for(auto itr: mp){
            ans.push_back(itr.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
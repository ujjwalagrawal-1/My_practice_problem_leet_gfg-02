class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,pair<int,int>>  mp;
        for(int i = 0;i<s.size();i++){
            if(mp.count(s[i])){
                mp[s[i]].second = i;
            }
            else{
                mp[s[i]] = {i,i};
            }
        }
        vector<int> ans;
        int maxi = mp[s[0]].second;
        int prev = 0;
        for(int i = 0;i<s.size();i++){
            if(i != maxi){
                maxi = max(maxi,mp[s[i]].second);
            }
            if(i == maxi){
                ans.push_back(maxi - prev+1);
                prev = i+1;
            }
        }
        return ans;
    }
};
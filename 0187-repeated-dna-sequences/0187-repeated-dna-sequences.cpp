class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        int i = 0;
        int j = 0;
        while(j < s.size()){
            if(j-i+1 == 10){
                mp[s.substr(i,10)]++;
                i++;
            }
            j++;
        }
        vector<string> ans;
        for(auto itr : mp){
            if(itr.second > 1)
            ans.push_back(itr.first);
        }

        return ans;
    }
};
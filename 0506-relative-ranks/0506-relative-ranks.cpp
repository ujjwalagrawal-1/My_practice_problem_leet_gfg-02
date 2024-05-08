class Solution {
public:
static bool comp(int a,int b){return a > b;}
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> veci(score.begin(), score.end());
        sort(veci.begin(), veci.end(),comp);
        for(auto itr: veci){
            cout<<itr<<" ";
        }
        map<int,string> mp;
        for(int i = 0;i<veci.size();i++){
            if(i == 0)
            mp[veci[i]] = "Gold Medal";
            else if (i == 1)
            mp[veci[i]] = "Silver Medal";
            else if(i == 2)
            mp[veci[i]] = "Bronze Medal";
            else{
                mp[veci[i]] = to_string(i+1);
            }
        }

        vector<string> fk;
        for(int i = 0;i<score.size();i++){
            fk.push_back(mp[score[i]]);
        }
        return fk ;
    }
};
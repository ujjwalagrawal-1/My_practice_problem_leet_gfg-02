typedef long long ll;
class Solution {
public:
bool c(map<char,int> &mp,map<char,int>& sec){
    for(auto itr : mp){
        if(sec.count(itr.first)){
            if(itr.second <= sec[itr.first]){
                continue;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    return true;
}
    string minWindow(string s, string t) { 
        map<char,int> mp;
        map<char,int> sec;
        for(int i = 0;i < t.size();i++){
            mp[t[i]]++;
        }
        ll i = 0;ll j = 0;
        ll len = INT_MAX;
        int ind = -1;
        while(j < s.size()){
            sec[s[j]]++;
            while(c(mp,sec) && j - i + 1 >= t.size()){
                if(j-i+1 < len){
                    len = j-i+1;
                    ind = i;
                }
                sec[s[i]]--;
                i++;
            }
            j++;
        }
        if(ind == -1){
            return "";
        }
        return s.substr(ind,len);

    }
};
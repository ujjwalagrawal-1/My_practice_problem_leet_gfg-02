class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int i = 0;
        int j = 0;
        map<char,int>mp;
        while(j < s.size()){
            mp[s[j]]++;
            if(j-i+1 == k){
                if(mp.size() == 1){
                    bool fl = 1;
                    if(i >= 1 && s[i-1] == s[i]){
                        fl &= 0;
                    }
                    if(j < s.size()-1 && s[j] == s[j+1]){
                        fl &= 0;
                    }
                    if(fl){
                        return true;
                    }
                    else{
                        mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    }
                }
                else{
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                }
                i++;
            }
            j++;
        }
        return false;
    }
};
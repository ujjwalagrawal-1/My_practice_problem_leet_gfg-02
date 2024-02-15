class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int cnt = 0;
        int i = 0;int j = 0;int flag = 1;
        while(j<s.size()){
            if(flag)
            mp[s[j]]++;
            if(mp.size() != 3)flag = 1;
            if(mp.size() == 3){
                flag = 0;
                cnt += s.size()-j;
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            if(flag)
            j++;
        }
        return cnt;

    }
};
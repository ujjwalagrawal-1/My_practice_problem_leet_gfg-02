class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;

        map<char,int> mp;
        while(j < s.size()){
            mp[s[j]]++;
            while(mp.size() == 3){
                ans += (s.size() - j);
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
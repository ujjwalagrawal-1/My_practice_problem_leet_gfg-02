class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mp;
        for(auto itr:s){
            mp[itr]++;
        }
        char ch = '/';
        for(int i = 0;i<s.size();i++){
            if(mp[s[i]] == 1){
                return i;
                break;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask=0;
        int maxlen=0;
        unordered_map<int,int>location;
        unordered_map<char,int>vowel = {{'a',0}, {'e',1} , {'i',2},{'o',3},{'u',4}};
        location[0]=-1;
        for(int i=0;i<s.size();i++){
            if(vowel.find(s[i]) != vowel.end()){
                mask ^= (1<<vowel[s[i]]);
            }
            if(location.find(mask) != location.end()){
                maxlen=max(maxlen,i-location[mask]);
            }
            else{
                location[mask]=i;
            }
        }
        return maxlen;
    }
};
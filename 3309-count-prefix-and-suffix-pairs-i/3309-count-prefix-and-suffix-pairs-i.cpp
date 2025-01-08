class Solution {
public:
bool solve(string &s1,string &s2){
    int i = 0;
    int j = s2.size()-1;
    int y = 0;
    while(y<s1.size() && s1[y] == s2[i]){
        y++;i++;
    }
    int t = s1.size()-1;
    while(t>= 0 && s2[j] == s1[t]){
        j--;t--;
    }
    if(t < 0 && y == s1.size()){
        return true;
    }
    return false;
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i = 0;i<words.size()-1;i++){
            for(int j = i+1;j<words.size();j++){
                if(words[i].size() > words[j].size()){
                    continue;
                }
                if(solve(words[i],words[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
int f(string s,int i,int j){
    int count = 0;
    while(i>=0 && j<=s.size() && s[i] == s[j]){
        count++;
        i--;j++;
    }
    return count;
}
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0;i<s.size();i++){
            count += f(s,i,i+1);
            count += f(s,i,i);
        }
        return count;
    }
};
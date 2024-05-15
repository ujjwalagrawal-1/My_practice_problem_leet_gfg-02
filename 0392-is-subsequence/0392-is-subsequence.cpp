class Solution {
public:
bool f(string &s,string &t,int i,int j){
    if(i == s.size()){
        return true; 
    }
    if(j == t.size()){
        return  false;
    }
    if(s[i] == t[j]){
        return f(s,t,i+1,j+1);
    }
    return f(s,t,i,j+1);
}
    bool isSubsequence(string s, string t) {
        if(s.length() >= t.length()){
            if(s == t){
                return 1;
            }
            return 0;
        }
        return f(s,t,0,0);
    }
};
class Solution {
public:
bool isPlaindrome(string str){
    int s = 0;int e = str.size()-1;
    while(s <= e){
        if(str[s] != str[e]){return false;}
        s++;e--;
    }
    return true;
}
void solve(string s,int ind,vector<vector<string>> & veci,vector<string> &curr){
    if(ind == s.size()){
        veci.push_back(curr);
        return;
    }
    for(int i = ind;i<s.size();i++){
        string e = s.substr(ind,i - ind + 1);
        if(isPlaindrome(e)){
            curr.push_back(e);
            solve(s,i+1,veci,curr);
            cout<<e<<endl;
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> veci;
        vector<string> curr;
        solve(s,0,veci,curr);
        return veci;
    }
};
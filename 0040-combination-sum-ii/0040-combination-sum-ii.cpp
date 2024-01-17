#define pb push_back
#define pob pop_back

class Solution {
public:
void solve_using_rec(vector<int>& c,int t,vector<vector<int>> &veci,vector<int> temp,int index){
    //base condition
    if(t == 0){
        veci.pb(temp);
        return;
    }
    // recursive relation

    for(int i = index;i<c.size();i++){
        if(i > index && c[i] == c[i-1])continue;
        if(c[i] > t)break;
        temp.pb(c[i]);
        solve_using_rec(c,t-c[i],veci,temp,i+1);
        temp.pob();
    }
    

}
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> veci;vector<int> temp;
        sort(c.begin(),c.end());
        solve_using_rec(c,target,veci,temp,0);
        return veci;
    }
};
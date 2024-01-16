#define pb push_back
#define pob pop_back 
class Solution {
public:

void solve_using_rec(vector<int>& c,int t,vector<vector<int>> &veci,vector<int> temp,int i){
    //base condition
    if(i >= c.size()){
        return;
    }
    if(t == 0){
        veci.pb(temp);
        return;
    }
    if(t < 0){
        return;
    }
    // recursive relation
    temp.pb(c[i]);
    solve_using_rec(c,t-c[i],veci,temp,i);
    temp.pob();
    solve_using_rec(c,t,veci,temp,i+1);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> veci;vector<int> temp;
        solve_using_rec(candidates,target,veci,temp,0);
        return veci;
    }
};
class Solution {
public:
void solve_using_recursion(vector<vector<int>> &ans,vector<int> veci,int k,int n,int sum,int i){
    if(veci.size() == k && sum == n){
        ans.push_back(veci);
        return;
    }

    for(int itr = i;itr<=9;itr++){
        if(itr+sum > n)break;
        veci.push_back(itr);
        solve_using_recursion(ans,veci,k,n,sum + itr,itr+1);
        veci.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        int i = 1;
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> veci;
        solve_using_recursion(ans,veci,k,n,sum,i);
        return ans;
    }
};
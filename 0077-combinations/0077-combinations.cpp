class Solution {
public:

void solve(vector<vector<int>> &ans,int n,int k,vector<int> temp_store,int start){
    if(temp_store.size() == k){
        ans.push_back(temp_store);
        return;
    }

    for(int i = start;i <= n;i++){
        temp_store.push_back(i);
        solve(ans,n,k,temp_store,i+1);
        temp_store.pop_back();

    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp_store;
        solve(ans,n,k,temp_store,1);
        return ans;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(arr.size());
        ans[0] = arr[0];
        for(int i = 1;i<arr.size();i++){
            ans[i] = ans[i-1]^arr[i];
        }
        vector<int> a(queries.size());
        for(int i = 0;i<queries.size();i++){
            int k = queries[i][0];
            int l = queries[i][1];
            if(k-1 < 0){
                a[i] = ans[l];
            }
            else
            a[i] = ans[l]^ans[k-1];
        }
        return a;
    }
};
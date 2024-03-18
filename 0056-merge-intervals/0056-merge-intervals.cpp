class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& val) {
        sort(val.begin(),val.end());
        // for(int i = 0;i<val.size();i++){
        //     cout<<val[i][0]<<" "<<val[i][1]<<endl;
        // }
        vector<vector<int>> ans;
        int n = val.size();
        for(int i = 0;i<n;){
            int ind = i+1;
            int mini = val[i][0];
            int maxi = val[i][1];
            while(ind < n && maxi >= val[ind][0]){
                if(maxi < val[ind][1]){
                    maxi = val[ind][1];
                }
                ind++;
            }
            ans.push_back({mini,maxi});
            i = ind;
        }
        return ans;
    }
};
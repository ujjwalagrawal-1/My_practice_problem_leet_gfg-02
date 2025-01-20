class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,int> a,b;
        map<int,pair<int,int>> mp;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0 ;j<mat[0].size();j++){
                mp[mat[i][j]] = {i,j}; 
            }
        }
        int i = 0;
        while(i<arr.size()){
            a[mp[arr[i]].first]++;
            b[mp[arr[i]].second]++;
            if(a[mp[arr[i]].first] == mat[0].size())break;
            if(b[mp[arr[i]].second] == mat.size())break;
            i++;
        }

        return i;
    }
};
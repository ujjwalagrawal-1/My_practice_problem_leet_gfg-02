class Solution {
public:
int meta(int a,int b){
    return a >= b ? a:b;
}

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int maxi = 0;

        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] != 0 && i>0){
                    matrix[i][j] = matrix[i-1][j] + 1;
                }
            }
            vector<int> veci = matrix[i];
            sort(veci.begin(),veci.end());
            for(int i = 0;i<veci.size();i++){
            maxi = meta(maxi,veci[i]*(veci.size()-i));
            }
        }
        return maxi;
    }
};
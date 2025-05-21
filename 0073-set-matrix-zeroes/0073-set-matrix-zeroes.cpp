class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        bool a = 0,b = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<n;i++){
            if(mat[i][0] == 0){
                a = 1;
            }
        }
        for(int i = 0;i<m;i++){
            if(mat[0][i] == 0){
                b = 1;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        for(int i = 1;i<n;i++){
            if(mat[i][0] == 0){
                for(int j = 0;j<m;j++){
                    mat[i][j] = 0;
                }
            }
        }
        for(int i = 1;i<m;i++){
            if(mat[0][i] == 0){
                for(int j = 0;j<n;j++){
                    mat[j][i] = 0;
                }
            }
        }
        if(a == 1){
            for(int i = 0;i<n;i++){
                mat[i][0] = 0;
            }
        }
        if(b == 1){
            for(int i = 0;i<m;i++){
                mat[0][i] = 0;
            }
        }
    }
};
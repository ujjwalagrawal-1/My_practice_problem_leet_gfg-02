class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> veci(matrix[0].size(),vector<int>(matrix.size()));
        int mini = min(matrix.size(),matrix[0].size());
        bool flag = 1;
        
        
        // for(int j = 0;j<mini;j++){
        //     swap(matrix[0][j],matrix[0][i]);
        // }
        // for(int i = 0;;i<mini;i++){
        //     swap(matrix[i][j],matrix[j][i]);
        // }
        
        // // cout<<" sex"<<i<<"     "<<j<<endl;
        // int i = mini-1;
        // int j = mini-1;
        // while(i != matrix.size()-1 || j != matrix[0].size()-1){
        //     while(j <= matrix[0].size()-1){
        //         j++;
        //         for(int x = 0;x<matrix.size();x++){
        //             int val = matrix[x][j];
        //             matrix[x].pop_back();
        //             i+=1;
        //             matrix[i].push_back(val);
        //         }
        //     }
        //     while(i <= matrix[0].size()-1){
        //         i++;
        //         for(int y = 0;y<matrix.size();y++){
        //             int val = matrix[y][i];
        //             matrix[y].pop_back();
        //             j+=1;
        //             matrix[j].push_back(val);
        //         }
        //     }
        // }
        // return matrix;


        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                veci[j][i] = matrix[i][j];
            }
        }
        return veci;
    }
};
class Solution {
public:
    void traverse(int i,int j,vector<vector<int>>& cell){
        for(int k=i-1;k>=0;k--){ // up side traverse
            if(cell[k][j]==3 or cell[k][j]==2) break;
            else cell[k][j]=1;
        }
        for(int k=i+1;k<cell.size();k++){ //down side traverse
            if(cell[k][j]==3 or cell[k][j]==2) break;
            else cell[k][j]=1;
        }
        for(int k=j-1;k>=0;k--){ //left side traverse
            if(cell[i][k]==3 or cell[i][k]==2) break;
            else cell[i][k]=1;
        }
        for(int k=j+1;k<cell[i].size();k++){ //right side traverse
            if(cell[i][k]==3 or cell[i][k]==2) break;
            else cell[i][k]=1;
        }
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> cell(m, vector<int>(n));
        for(int i=0;i<guards.size();i++){
            cell[guards[i][0]][guards[i][1]]=2;
        }
        for(int i=0;i<walls.size();i++){
            cell[walls[i][0]][walls[i][1]]=3;
        }
        for(int i=0;i<guards.size();i++){
            traverse(guards[i][0],guards[i][1],cell);
        }
        int count=0;
        for(auto x:cell){
            for(auto y:x)
                if(y==0) count++;
        }
        return count;
    }
};
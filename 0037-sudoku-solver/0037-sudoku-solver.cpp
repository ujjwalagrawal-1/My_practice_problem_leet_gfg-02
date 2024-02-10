class Solution {
public:
bool isValid(vector<vector<char>> &board,int row,int col,char c){

    for(int i = 0;i<9;i++){
        if(board[row][i] == c){
            return false;
        }
        if(board[i][col] == c){
            return false;
        }
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c){
            return false;
        }
    }
    return true;
}

bool f(vector<vector<char>> &board){
    for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9; j++){
                if(board[i][j] == '.'){
                    for(int t = 0;t < 9; t++){
                        char c = '1'+t;
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                        
                        if(f(board)){
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                        }
                        }
                    }
                return false;
                }
            }
        }
        return true;  
}
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};
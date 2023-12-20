class Solution {
public:
    void Solve(int col, int n, vector<vector<string>> &answer, vector<string> &dfmat, vector<int> &veci1, vector<int> &updiagonal, vector<int> &downDiagonal) {
        if (col == n) {
            answer.push_back(dfmat);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (veci1[i] == 0 && updiagonal[n-1+col-i] == 0 && downDiagonal[i+col] == 0) {
                dfmat[i][col] = 'Q';
                veci1[i] = 1;
                updiagonal[n-1+col-i] = 1;
                downDiagonal[i+col] = 1;
                Solve(col+1, n, answer, dfmat, veci1, updiagonal, downDiagonal);
                dfmat[i][col] = '.';
                veci1[i] = 0;
                updiagonal[n-1+col-i] = 0;
                downDiagonal[i+col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> dfmat(n, string(n, '.'));
        vector<int> veci1(n, 0), updiagonal(2*n -1, 0), downDiagonal(2*(n)-1, 0);
        vector<vector<string>> answer;
        int col = 0;
        Solve(col, n, answer, dfmat, veci1, updiagonal, downDiagonal);
        return answer;
    }
};

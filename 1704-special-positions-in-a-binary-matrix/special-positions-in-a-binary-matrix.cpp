class Solution {
public:
    
    int row[105] = {},col[105] = {};
    int numSpecial(vector<vector<int>>& mat)
    {
        int ans = 0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    row[i]++,col[j]++;
            }
        }    
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1 && (row[i]==1 && col[j]==1))
                    ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
         vector<int> cnt(3,0);
        int i = 0;
        int j = 0;
        int c = 0;
        while(i<=(grid.size())/2){
            cnt[grid[i][j]]++;
            i++;j++;
            c++;
        }
        i = int(grid.size()/2) - 1;
        j = int(grid.size()/2) + 1;
        while(i>=0){
            cnt[grid[i][j]]++;
            i--;j++;
            c++;
        }
        i = grid.size()/2 + 1;
        j = grid.size()/2;
        while(i<grid.size()){
            cnt[grid[i][j]]++;
            i++;
            c++;
        }
        vector<int> sec(3,0);
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                sec[grid[i][j]]++;
            }
        }

        for(int i = 0;i<3;i++){
            sec[i] -= cnt[i];
        }
        int sum = 0;
        for(int i = 0;i<3;i++){
            sum += sec[i];
            sum += cnt[i];
        }
        int miniopr = INT_MAX;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(i == j)continue;
                miniopr = min(miniopr,sum - sec[i] - cnt[j]);
            }
        }
        return miniopr;
    }
};
class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        vector<vector<int>> veci;
        veci.push_back({0,0});
        int i = 0;
        while( i<m.size()){
            int j = i+1;
            while(j<m.size() && m[j][0] <= m[i][1]){
                m[i][1] = max(m[i][1],m[j][1]);
                j++;
            }
            veci.push_back({m[i][0],m[i][1]});
            i = j;
        }
        int ans = 0;
        if(veci[0][0] > days)return 0;
        for(int i = 1;i<veci.size();i++){
            if(veci[i][0] > days){
                ans += max(days,veci[i-1][1]) - days;
            }
            else{
                ans += veci[i][0] - veci[i-1][1]-1;
            }
        }
        if(days > veci[veci.size()-1][1]){
            ans += (days - veci[veci.size()-1][1]);
        }
        return ans;
    }
};
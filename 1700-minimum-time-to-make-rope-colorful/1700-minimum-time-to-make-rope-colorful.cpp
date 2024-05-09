class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        int ans = 0;int prevind = 0;
        for(int i = 1;i<colors.size();i++){
            if(colors[i] == colors[prevind]){
                if(nt[prevind] > nt[i]){
                    ans += nt[i];
                }
                else{
                    ans += nt[prevind];
                    prevind = i;
                }
            }
            else{
                prevind = i;
            }
        }
        return ans;
    }
};
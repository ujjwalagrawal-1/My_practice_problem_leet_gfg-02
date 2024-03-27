class Solution {
public:
    int maxSatisfied(vector<int>& cst, vector<int>& g, int min) {
        int val = 0;
        for(int i = 0;i<cst.size();i++){
            if(g[i] == 0){
                val += cst[i];
            }
        }
        int i = 0,j = 0;
        int ans = val;
        while(j<cst.size()){
            if(g[j] == 1){
                val += cst[j];
            }
            if(j-i+1 > min){
                if(g[i] == 1){
                    val -= cst[i];
                }
                i++;
            }
            if(j-i+1 == min){
                ans = max(ans,val);
            }
            j++;
        }
        return ans;
    }
};
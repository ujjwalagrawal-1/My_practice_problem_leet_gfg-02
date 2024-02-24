class Solution {
public:
// int fun(vector<int> &veci,int goal){
// }
    int numSubarraysWithSum(vector<int>& veci, int goal) {
        int i = 0;int j = 0;int cal = 0;int ans = 0;
        while(j<veci.size()){
            cal += veci[j];
            while(i<j && cal > goal){
                cal -= veci[i];
                i++;
            }
            if(cal == goal){
                int ind = i;
                while(ind<j && veci[ind] == 0){
                    ans++;
                    ind++;
                }
                ans++;
            }
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    int numSub(string s) {
        int M = 1000000007;
        int i = 0;
        int j = 0;
        int ans = 0;
        // 001110
        while(j<s.size()){
            if(s[j] == '1'){
                j++;
            }
            else{
                ans = (ans + 1ll*(j-i)*(j-i+1)/2)%M;
                j++;
                i = j;
            }
        }
        ans = (ans + (j-i)*(j-i+1)/2)%M;
        return ans;
    }
};
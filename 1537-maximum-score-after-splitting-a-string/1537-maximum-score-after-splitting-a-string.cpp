class Solution {
public:
    int maxScore(string s) {
        int zros = 0;
        int ones = 0;
        for(int i =  0;i<s.size();i++){
            if(s[i] == '0'){
                zros++;
            }
            else{
                ones++;
            }
        }
        int a = 0,b = 0,ans = INT_MIN;
        for(int i = 0;i<s.size()-1;i++){
            if(s[i] == '0'){
                a++;
            }
            else{
                b++;
            }
            ans = max(ans,a + ones-b);
        }
        return ans;
    }
};
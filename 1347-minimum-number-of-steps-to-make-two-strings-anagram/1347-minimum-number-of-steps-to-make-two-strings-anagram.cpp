class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        for(int i = 0;i<t.size();i++){
            int n = t.find(s[i]);
            if(n != std::string::npos){
                t[n] ='/';
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};
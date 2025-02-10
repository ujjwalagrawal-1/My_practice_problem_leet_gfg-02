class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(int i = 0;i<s.size();i++){
            if(s[i]-'0' <= 9 && s[i]-'0' >= 0){
                if(!ans.empty())
                ans.pop_back();
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};
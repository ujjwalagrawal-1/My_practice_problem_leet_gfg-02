class Solution {
public:
    string makeGood(string s) {
        if(s.empty()) return "";

        string ans = "";
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(!ans.empty() && abs(c - ans.back()) == 32) {
                ans.pop_back(); 
            } else {
                ans.push_back(c); 
            }
        }
        return ans;
    }
};

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string zero = "";
        string one  = "";
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1'){
                one += "1";
            }
            else{
                zero += "0";
            }
        }
        one.pop_back();
        string ans = one + zero;
        ans += '1';
        return ans;
    }
};
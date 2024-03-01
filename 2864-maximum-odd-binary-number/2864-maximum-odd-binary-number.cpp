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
        one += zero;
        one += '1';
        return one;
    }
};
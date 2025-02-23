class Solution {
public:
bool f(string &s){
    for(int i = 0;i<s.size();i++){
        if(s[i] != s[0]){
            return false;
        }
    }
    return true;
}
    bool hasSameDigits(string s) {
        int i = 0;
        bool fl = 1;
        string temp = "";
        while(fl && s.size() > 2){
            if(f(s)){
                return true;
            }
            i = 0;
            temp = "";
            while(i < s.size()-1){
                // cout<<temp<<endl;
                temp += to_string(((s[i] - '0') + (s[i+1] - '0'))%10);
                i++;
            }
            s = temp;
        }
        if(f(s)){
                return true;
        }
        return false;
    }
};
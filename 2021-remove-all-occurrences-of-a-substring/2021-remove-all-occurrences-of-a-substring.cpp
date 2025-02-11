class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp = "";
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            temp += s[i];
            cnt++;
            if(cnt >= part.size() && temp.ends_with(part)){
                cnt -= part.size();
                temp.resize(cnt);
            }
        }
        return temp;
    }
};
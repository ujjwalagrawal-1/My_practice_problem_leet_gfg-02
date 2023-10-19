class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // stack<int>st;
        string st1 = "",st2 = "";
        for(auto itr:s){
            if(itr == '#'){
                if(st1.length() == 0){
                    continue;
                }
                else{
                    st1.pop_back();
                }
            }
            else{
                st1.push_back(itr);
            }
        }
        for(auto itr:t){
            if(itr == '#'){
                if(st2.length() == 0){
                    continue;
                }
                else{
                    st2.pop_back();
                }
            }
            else{
                st2.push_back(itr);
            }
            
        }
        return st1 == st2;
    }
};
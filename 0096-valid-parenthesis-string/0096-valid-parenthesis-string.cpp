class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int i = 0;
        int bonus = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                st.push('(');
            }
            else if(s[i] == '*'){
                bonus++;
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else if(bonus){
                    bonus--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
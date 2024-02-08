class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int j = 0;
        while(j<s.size()){
            if(st.empty()){
                st.push(s[j]);
            }
            else{
                char t = s[j];
                if(st.top() == '(' && t == ')'){
                    st.pop();
                }
                else{
                    st.push(t);
                }
            }
            j++;
        }
        return st.size();
    }
};
class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        string ans = "";
        int x = 0;
        while(x<s.size()){
            if(s[x] != ' '){
                st.push(s[x]);
            }
            else{
                if(s[x] == ' ' && st.empty()){
                    continue;
                }
                else{
                while(!st.empty()){
                    ans += st.top();
                    st.pop(); 
                }
                ans += ' ';
                }
            }
            x++;
        }

        if(!st.empty()){
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};
class Solution {
public:
    int clumsy(int n) {
        if (n == 1) return 1;
        
        int ans = 0;
        stack<int> st;
        st.push(n--);
        
        int op = 0;
        
        while (n > 0) {
            if (op == 0) {
                st.top() *= n;
            } else if (op == 1) {
                st.top() /= n;
            } else if (op == 2) {
                st.push(n);
            } else {
                st.push(-n);
            }
            op = (op + 1) % 4;
            n--;
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
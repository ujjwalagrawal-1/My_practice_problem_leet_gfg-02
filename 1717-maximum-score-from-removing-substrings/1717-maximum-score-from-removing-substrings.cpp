class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int maxi, mini;
        char first, second;

        if (x > y) {
            maxi = x;
            mini = y;
            first = 'a';
            second = 'b';
        } else {
            maxi = y;
            mini = x;
            first = 'b';
            second = 'a';
        }

        stack<char> st;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == first && s[i] == second) {
                st.pop();
                ans += maxi;
            } else {
                st.push(s[i]);
            }
        }

        string remaining = "";
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (int i = 0; i < remaining.size(); i++) {
            if (!st.empty() && st.top() == second && remaining[i] == first) {
                st.pop();
                ans += mini;
            } else {
                st.push(remaining[i]);
            }
        }

        return ans;
    }
};

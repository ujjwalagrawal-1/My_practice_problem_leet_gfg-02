class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        vector<int> ans(h.size(), 0);
        stack<int> st;
        for(int i = h.size()-1; i >= 0; i--){
            int count = 0;
            while(!st.empty() && st.top() < h[i]){
                count++;
                st.pop();
            }
            if(!st.empty()) count++;
            
            st.push(h[i]);
            ans[i] = count;
        }
        return ans;
    }
};

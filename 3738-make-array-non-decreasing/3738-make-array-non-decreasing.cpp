class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> st;
        for(auto& itr : nums){
            if(!st.empty() && st.top() > itr){
                itr = st.top();
                st.pop();
            }
            st.push(itr);
        }
        return st.size();
    }
};
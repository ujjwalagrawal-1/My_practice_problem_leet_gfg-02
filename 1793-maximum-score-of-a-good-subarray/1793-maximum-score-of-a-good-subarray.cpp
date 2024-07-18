class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        int maxScore = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] < k && right[i] > k) {
                int score = nums[i] * (right[i] - left[i] - 1);
                maxScore = max(maxScore, score);
            }
        }
        
        return maxScore;
    }
};

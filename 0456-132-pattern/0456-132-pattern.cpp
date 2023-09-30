// class Solution {
// public:
//     vector<int> prevsmallestelement(vector<int>& veci) {
//         stack<int> st;
//         vector<int> ans(veci.size()); // Initialize ans with the same size as veci
//         st.push(INT_MIN); // Push INT_MAX instead of INT_MIN
//         int w = 0;
//         for(int d = 0 ;d<veci.size();d++) {
//             int t = veci[d];
//             while (!st.empty() && t <= st.top()) { // Correct the condition
//                 st.pop();
//             }
//             if (st.top() == INT_MIN) { // Check if the stack top is INT_MAX
//                 ans[d] = veci[d];
//             }
//             else {
//                 ans[d] = st.top();
//             }
//             st.push(t);
//         }

//         for(auto itr:ans){
//             cout<<itr<<"  ";
//         }
//         cout<<endl;
//         return ans;
//     }


//     vector<int> nextsmallestelement(vector<int>& veci) {
//         stack<int> st;
//         vector<int> ans(veci.size()); // Initialize ans with the same size as veci
//         st.push(INT_MIN); // Push INT_MAX instead of INT_MIN
//         int w = 0;
//         for(int d = veci.size()-1;d>=0;d--) {
//             int t = veci[d];
//             while (!st.empty() && t <= st.top()) { // Correct the condition
//                 st.pop();
//             }
//             if (st.top() == INT_MIN) { // Check if the stack top is INT_MAX
//                 ans[d] = veci[d];
//             }
//             else {
//                 ans[d] = st.top();
//             }
//             st.push(t);
//         }
//         for(auto itr:ans){
//             cout<<itr<<"  ";
//         }
//         return ans; 
//     }

//     bool find132pattern(vector<int>& nums) {
//         vector<int> xt = prevsmallestelement(nums);
//         vector<int> xz = nextsmallestelement(nums);
//         for (int i = 1; i < nums.size()-1;i++) {
//             int x = xt[i-1];
//             int y = nums[i];
//             int z = xz[i+1];
            

//             if (x < y && y > z && x<z) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int third = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third) return true;
            while (!s.empty() && s.top() < nums[i]) {
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

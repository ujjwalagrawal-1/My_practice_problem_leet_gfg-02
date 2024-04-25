class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        for(int i = 0;i<nums.size();i++){
            while(!st.empty() && st.size()+nums.size()-i-1 >= k && st.top() > nums[i]){
                st.pop();
            }

            if(st.size() < k){
                st.push(nums[i]);
            }
        }

    vector<int>answer;
    while(!st.empty()){
        answer.push_back(st.top());st.pop();
    }
    reverse(answer.begin(),answer.end());
    return answer;
    }
};
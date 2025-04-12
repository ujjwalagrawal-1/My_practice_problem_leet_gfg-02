class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        for(auto itr : nums){
            st.insert(itr);
        }
        if(k > *st.begin()){
            return -1;
        }
        else{
            return k == *st.begin() ? st.size()-1 : st.size();
        }
    }
};
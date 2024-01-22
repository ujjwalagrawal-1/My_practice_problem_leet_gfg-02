class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> st;
        int i = 0;
        for(auto itr:nums){
            if(st.find(itr) != st.end()){
                i = itr;
            }
            st.insert(itr);
        }
        int j = 0;
        for(int i = 1;i<=nums.size();i++){
            if(st.find(i) == st.end()){
                j = i;
                break;
            }
        }
        return {i,j};
    }
};
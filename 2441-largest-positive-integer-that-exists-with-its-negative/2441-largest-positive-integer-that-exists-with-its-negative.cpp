class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st;
        for(auto itr:nums){
            st.insert(itr);
        }
        int maxi = -1;
        for(auto itr:st){
            if(st.count(-itr)){
                maxi = max(maxi,abs(itr));
            }
        }
        return maxi;
    }
};
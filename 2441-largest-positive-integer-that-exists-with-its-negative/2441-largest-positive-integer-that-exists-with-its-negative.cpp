class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st;
        // vectro<int> pos;
        for(auto itr:nums){
            st.insert(itr);
        }
        bool f = 0;
        int maxi = -1;
        for(auto itr:st){
            if(st.count(-itr)){
                maxi = max(maxi,abs(itr));
            }
        }
        return maxi;
    }
};
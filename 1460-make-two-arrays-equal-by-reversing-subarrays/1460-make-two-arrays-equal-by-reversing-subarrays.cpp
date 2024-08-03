class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> st;
        for(auto itr:target){
            st[itr]++;
        }
        for(auto itr:arr){
            if(!st.count(itr)){
                return false;
            }
            else{
                st[itr]--;
                if(st[itr] == 0){
                    st.erase(itr);
                }
            }
        }
        return true;
    }
};
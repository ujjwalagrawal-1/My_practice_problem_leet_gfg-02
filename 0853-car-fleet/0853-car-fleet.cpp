class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> veci;
        for(int i = 0;i<speed.size();i++){
            veci.push_back({position[i],speed[i]});
        }
        sort(veci.begin(),veci.end());
        stack<float> st;
        for(auto itr: veci){
            float val = ((target-itr.first)*1.0)/itr.second;
            while(!st.empty() && st.top()<=val){
                st.pop();
            }
        st.push(val);
        }
        return st.size();
    }
};
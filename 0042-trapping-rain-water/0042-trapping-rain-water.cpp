class Solution {
public:
    int trap(std::vector<int>& ht) {
        stack<int> st;
        st.push(INT_MIN);
        vector<int> veci(ht.size());
        vector<int> veci2(ht.size());
        int i = 0;
        while(i<ht.size()){
            if(!st.empty() && st.top() < ht[i]){
                st.push(ht[i]);
            }
            veci[i] = st.top();
            i++;
        }
        while(!st.empty()){
            st.pop();
        }
        st.push(INT_MIN);
        i = ht.size()-1;
        for(auto itr:veci){
            cout<<itr<<" ";
        }cout<<endl;
        while(i >= 0){
            if(!st.empty() && st.top() < ht[i]){
            st.push(ht[i]);
            }
            veci2[i] = st.top();
            i--;
        }
        int ans = 0;
        for(int i = 0;i<veci.size();i++){
            ans += min(veci[i],veci2[i]) >= ht[i] ?  min(veci[i],veci2[i])- ht[i]:0;
        }

        return ans;

    }
};
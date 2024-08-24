class Solution {
public:
static bool comp(vector<int> &a,vector<int> &b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}
    int numberOfWeakCharacters(vector<vector<int>>&  p) {
        sort(p.begin(),p.end(), comp);
        stack<int> st;
        for(int i = 0;i < p.size();i++){
            while(!st.empty() && p[st.top()][1] < p[i][1]){
                st.pop();
            }
            st.push(i);
        }

        return p.size() - st.size();
    }
};
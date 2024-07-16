
#define MOD 1000000007
class Solution {
public:
vector<int> findnextsmallest(vector<int> &veci){
    vector<int> ans(veci.size());
    stack<int> st;
    for(int i = veci.size()-1;i>=0;i--){
        while(!st.empty() && veci[st.top()] >= veci[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = veci.size();
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> findprevsmallest(vector<int> &veci){
    vector<int> ans(veci.size());
    stack<int> st;
    for(int i = 0;i<veci.size();i++){
        while(!st.empty() && veci[st.top()] > veci[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nextsmallest = findnextsmallest(arr);
        vector<int> prevsmallest = findprevsmallest(arr);
        int ans = 0;
        for(int i = 0;i<arr.size();i++){
            long long a = nextsmallest[i] - i;
            long long b = i - prevsmallest[i];
            ans = (ans + (a * b * arr[i]) % MOD) % MOD;          
        }
        return ans;
    }
};
class Solution {
public:
    long long calculateScore(vector<string>& in, vector<int>& v) {
        long long ans = 0;
        int ind = 0;
        set<int> st;
        while(ind < v.size()){
            if(st.count(ind)){
                return ans;
            }
            if(in[ind] == "add"){
                st.insert(ind);
                ans += v[ind];
                ind += 1;
            }
            else{
                st.insert(ind);
                ind += v[ind];
            }
        }
        return ans;
    }
};
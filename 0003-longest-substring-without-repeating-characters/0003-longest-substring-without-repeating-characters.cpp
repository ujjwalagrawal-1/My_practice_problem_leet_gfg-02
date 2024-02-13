class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int maxi = 0;
        set<char> st;
        while(j<s.size()){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                maxi = max(maxi,j-i+1);
                j++;
            }
            else if(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};
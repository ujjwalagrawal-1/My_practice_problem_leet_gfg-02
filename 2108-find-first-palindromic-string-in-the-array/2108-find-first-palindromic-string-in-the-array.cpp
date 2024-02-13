class Solution {
public:
bool isPalindrome(string st){
    int i = 0;int j = st.size()-1;
    while(i<j){
        if(st[i] != st[j]){
            return false;
        }
        i++;j--;
    }
    return true;
}
    string firstPalindrome(vector<string>& words) {
        for(auto itr:words){
            if(isPalindrome(itr)){
                return itr;
            }
        }
        return "";
    }
};
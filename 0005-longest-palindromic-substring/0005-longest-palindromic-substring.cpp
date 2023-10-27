class Solution {
public:

string extract_palindrome(string s,int i,int j){
    while(i>=0 && j<s.size() && s[i] == s[j]){
        i--;j++;
    }
    return s.substr(i+1,j-i-1);
}
    string longestPalindrome(string s) {
        // vector<pair<int,string>> answer;
        string ans = "";
        // int longest_size = 0;
        for(int i = 0;i<s.size();i++){
            string odd = extract_palindrome(s,i,i);
            string even = extract_palindrome(s,i,i+1);
            ans = ans.size()<odd.size()?odd:ans;
            ans = ans.size()<even.size()?even:ans;
        }
        return ans;
    }
};
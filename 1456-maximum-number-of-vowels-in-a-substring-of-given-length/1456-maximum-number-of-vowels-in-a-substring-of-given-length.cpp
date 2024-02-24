class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int cv = 0;
        int ans = 0;
        while(j<s.size()){
            if(s[j] == 'a' || s[j] == 'e'||s[j] == 'i'||s[j] == 'o'||s[j] == 'u')cv++;
            if(j-i+1 == k){
                ans = max(ans,cv);
                if(s[i] == 'a' || s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u')cv--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
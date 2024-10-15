typedef long long ll;
class Solution {
public: 
    long long minimumSteps(string s) {
        ll ans= 0;
        ll i = 0;
        ll j = s.size()-1;
        while(i  <  j){
            while(i<j && s[i] == '0'){
                i++;
            }
            while(i<j && s[j] == '1'){
                j--;
            }
            if(i<j &&  s[i] == '1' && s[j] == '0'){
                ans += (j-i);
                i++;
                j--;
            }
        }
        return ans;
    }
};
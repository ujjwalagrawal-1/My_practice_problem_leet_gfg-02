class Solution {
public:
bool isvowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        return true;
    }
    return false;
}
    bool halvesAreAlike(string s) {
        int a = 0,b = 0;
        for(int i = 0;i<s.size();i++){
            if(isvowel(s[i]) && i < s.size()/2)a++;
            else{
                if(isvowel(s[i]))b++;
            }
        }
        return a == b;
    }
};
class Solution {
public:
    void reverseString(vector<char>& s) {
     stack<char> ans ;
     for(int i=0; i<s.size(); i++){
         ans.push(s[i]) ;
     } 
    int i=0;
     while(!ans.empty()){
        s[i] = ans.top() ;
         ans.pop() ;
         i++ ;
     }
    }
};

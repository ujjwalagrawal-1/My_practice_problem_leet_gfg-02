class Solution {
public:
void reversestr(vector<char>& st,int i,int j,char& temp){
  if(i>=j){
    return;
  }
  temp = st[j];
  st[j] = st[i];
  st[i] = temp;
  reversestr(st,i+1,j-1,temp);
}
    void reverseString(vector<char>& s) {
        int i = 0;int j = s.size()-1;char temp;
        reversestr(s,i,j,temp);
    }
};
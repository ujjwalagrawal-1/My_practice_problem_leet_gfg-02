class Solution {
public:
bool f(vector<int> &st,int ind,int prev,int mov){
    if(ind == st.size()-1){
        if(st[ind] == st[prev] + mov)return 1;
        return 0;
    }
    if(ind >= st.size()){
        return 0;
    }
    if(mov == 0){
        return 0;
    }
    if(st[ind] == st[prev] + mov){
        return f(st,ind+1,ind,mov+1) || f(st,ind+1,ind,mov-1) || f(st,ind+1,ind,mov);
    }
    else if(st[ind] < st[prev] + mov){
        return f(st,ind+1,prev,mov);
    }
    else{
        return 0;
    }
}
    bool canCross(vector<int>& st) {
        // Solve Using Recursion
        return f(st,1,0,1);
    }
};
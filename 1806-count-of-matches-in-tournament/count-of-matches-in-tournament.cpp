class Solution {
public:
void recursion(int n,int &matches){
    if(n == 1){
        return;
    }
    matches += n/2;

    if(n%2 == 0){
        recursion(n/2,matches);
    }
    else{
        recursion(n/2+1,matches);
    }
    
}
    int numberOfMatches(int n) {
        int matches =  0;
        recursion(n,matches);
        return matches;
    }
};
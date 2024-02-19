class Solution {
public:
bool solve(int n){
    if(n == 0){
        return 0;
    }

    return (n == 1 || (n%2 == 0 && solve(n/2)));
}
    bool isPowerOfTwo(int n) {
        return solve(n);
    }
};
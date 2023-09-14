class Solution {
public:
int solve(long n,long count){
    if(n == 0 || n==1){
        return 0;
    }
    if(n%2 == 1){
        long x = solve(n+1,count);
        long y = solve(n-1,count);
        return min(x,y)+1;
    }
    long t = solve(n/2,count++);
    count += t;
    return count;
}
    int integerReplacement(int n) {
        long count = 0;
        return solve(n,count);
    }
};
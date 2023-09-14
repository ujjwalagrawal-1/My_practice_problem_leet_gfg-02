class Solution {
public:
int recur(long n,long count){
    // if(n == 0 || n==1){
    //     return 0;
    // }
    // if(n%2 == 1){
    //     long x = solve(n+1,count);
    //     long y = solve(n-1,count);
    //     return min(x,y)+1;
    // }
    // long t = solve(n/2,count++);
    // count += t;
    // return count;
    if(n<=1)
        {return count;}
        if(n%2==0)
        {
            return recur(n/2,++count);
        }
        else
        {
            return min(recur(n-1,count),recur(n+1,count))+1;
        }
}
    int integerReplacement(int n) {
        long count = 0;
        return recur(n,count);

    /*
    recur(int n,int cnt=0)
    {
        if(n<=1)
        {return count;}

        if(n%2==0)
        {
            return recur(n/2,++count);
        }
        else
        {
            return min(recur(n-1,cnt),recur(n+1,count));
        }
    }
    */
    }
};
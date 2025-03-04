class Solution {
public:
int dp[16];
int f(int n,int index){
    if(n == 0){
        return true;
    }
    if(n < 0)return false;
    if(index < 0){
        return false;
    }
    return f(n-dp[index],index-1) || f(n,index-1);
}
    bool checkPowersOfThree(int n) {
        int mul = 1;
        for(int i = 0;i<16;i++){
            dp[i] = mul;
            mul*=3;
        }
        return f(n,15);
    }
};
class Solution {
public:
    int kthGrammar(int n, int k) {
        int x=pow(2,n-1);
        int flag=0;
        while(x!=1){
            x/=2;
            if(k>x){
                k-=x;
                flag=!flag;
            }
        }
        if(flag){
            return 1;
        }
        else{
            return 0;
        }
    }
};
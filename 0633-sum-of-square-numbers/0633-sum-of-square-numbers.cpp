class Solution {
public:
int squareroot(int c){
    if(c == 0)return 0;
    int s = 1;
    int e = c/2;
    int ans = 0;
    while(s<=e){
        int mid = s + (e - s )/2;
        if(mid == c / mid){
            return mid;
        }
        else if(mid < c/mid){
            ans = mid;
            s = mid + 1;
            
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}
    bool judgeSquareSum(int c) {
        if(c == 1)return true;
        long long int s = 0;
        long long int e = squareroot(c);
        while(s<=e){
            if(s*s + e*e == c){
                return true;
            }
            else if(s*s + e*e > c){
                e--;
            }
            else if(s*s + e*e < c){
                s++;
            }
        }
        return false;
    }
};
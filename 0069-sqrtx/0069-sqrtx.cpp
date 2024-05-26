class Solution {
public:
     long long mySqrt(int x) {
        if(x == 1){
            return 1;
        }
        long long s = 0;
        long long e = x/2;
        long long ans = -1;
        while(s <= e){
        long long mid = s + (e - s)/2;
        if(mid*mid == x){
            return mid;
        }
        else if(mid*mid > x){
            e = mid-1;
        }
        else{
            ans = mid;
            s = mid + 1;
        }
        }
        return ans;
    }
};
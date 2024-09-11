class Solution {
public:
    int minBitFlips(int start, int goal) {
        int t = start^goal;
        int ans = 0;
        while(t){
            t = t&(t-1);
            ans++;
        }
        return ans;
    }
};
typedef long long ll;
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int temp = 0, ans = 0;
        while (j < nums.size()){
            while ((temp & nums[j]) != 0) { 
                temp ^= nums[i];
                i++;
            }
            temp |= nums[j];
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
    // (tc) -> 1e5*32*2 => 1e5*64;
    // (sc) -> o(1);
};
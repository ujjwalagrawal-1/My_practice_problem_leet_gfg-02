class Solution {
public:
int f(vector<int> & nums,int k){
    int i = 0;
    int j = 0;
    int odd = 0;
    int val = 0;
    while(j<nums.size()){
        if(nums[j]%2 == 1){
            odd++;
        }
        while(i<=j && odd > k){
            if(nums[i]%2 == 1){
                odd--;
            }
            i++;
        }
        val += j-i+1;
        j++;
    }
    return val;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};
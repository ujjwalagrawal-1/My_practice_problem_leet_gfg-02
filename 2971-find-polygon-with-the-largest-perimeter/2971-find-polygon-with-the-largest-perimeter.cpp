class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        long long ans = -1;
        for(auto itr:nums){
            if(itr<sum)ans = itr + sum;
            sum += itr;
        }
        return ans;
    }
};
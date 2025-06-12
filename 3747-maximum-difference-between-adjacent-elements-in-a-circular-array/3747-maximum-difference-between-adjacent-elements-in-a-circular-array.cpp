class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        // if()
        nums.push_back(nums[0]);
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size()-1;i++){
            maxi = max(maxi,abs(nums[i]-nums[i+1]));
        }
        return maxi;
    }
};
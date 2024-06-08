class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> remaindersFound;
    int currSum = 0;
    remaindersFound[0] = -1; 

    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        int remainder = currSum % k;

        if (remaindersFound.count(remainder)) {
            
            if (i - remaindersFound[remainder] >= 2) {
                return true;
            }
        } else {
            remaindersFound[remainder] = i;
        }
    }

    return false;
}
};
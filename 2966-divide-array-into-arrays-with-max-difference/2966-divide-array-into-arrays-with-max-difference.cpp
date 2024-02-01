class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i+2<nums.size();i+=3){
            if(abs(nums[i] - nums[i+2])>k){
                return {};
            }
            else{
                vector<int> result(nums.begin()+i,nums.begin()+i+3);
                ans.push_back(result);
            }
        }
        return ans;
    }
};
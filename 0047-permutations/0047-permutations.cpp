class Solution {
public:
vector<vector<int>>ans;
void recursive_solve(vector<int>& nums,int i){
    if(i == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j = i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        recursive_solve(nums,i+1);
        swap(nums[i],nums[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<int>store;
        // vector<vector<int>>ans;

        recursive_solve(nums,0);
        return ans;
    }
};
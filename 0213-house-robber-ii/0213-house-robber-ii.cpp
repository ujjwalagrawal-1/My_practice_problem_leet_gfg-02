class Solution {
public:
    int spaceoptimisation(vector<int> &nums){
    int prev2 = 0;
    int prev = nums[0];

    for(int i = 1;i < nums.size();i++){
            int in = nums[i];
            if(i >=2)
            in += prev2;

            int ex = prev + 0;
            int ans = max(ex,in);
            prev2 = prev;
            prev = ans;
        }
        return prev;
}
    int rob(vector<int>& nums) {
        vector<int> vec1,vec2;
        if(nums.size() == 1){
            return nums[0];
        }
        for(int i = 0;i<nums.size();i++){
            if(i == 0){
                vec1.push_back(nums[i]);
            }
            else if(i == nums.size()-1){
                vec2.push_back(nums[i]);
            }
            else{
                vec1.push_back(nums[i]);
                vec2.push_back(nums[i]);
            }
        }
        for(auto itr:vec1){
            cout<<itr<<" ";
        }
        return max(spaceoptimisation(vec1),spaceoptimisation(vec2));
    }
};
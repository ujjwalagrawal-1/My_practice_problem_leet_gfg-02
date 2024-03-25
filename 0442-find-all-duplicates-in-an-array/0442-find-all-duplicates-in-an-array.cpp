class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int j = 0;
        vector<int>veci;
        while(j<nums.size()){
            if(mp[nums[j]]){
                veci.push_back(nums[j]);
            }
            else
            mp[nums[j]] = 1;

            j++;
        }
        return veci;
    }
};
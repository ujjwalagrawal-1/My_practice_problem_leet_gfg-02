class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0 ;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto itr : mp){
            if(itr.second&1){
                return 0;
            }
        }
        return 1;
    }
};
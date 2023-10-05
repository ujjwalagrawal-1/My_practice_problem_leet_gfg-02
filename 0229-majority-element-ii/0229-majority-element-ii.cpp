class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(auto itr:nums){
            mp[itr]++;
        }
        int n = nums.size();
        int x = (n/3);

        vector<int> ans;
        for(auto itr:mp){
            if(itr.second > x){
                ans.push_back(itr.first);
            }
        }
        return ans;
    }
};
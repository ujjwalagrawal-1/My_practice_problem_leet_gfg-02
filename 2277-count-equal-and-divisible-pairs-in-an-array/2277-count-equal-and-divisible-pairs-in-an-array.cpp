class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        map<int,vector<int>> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto& itr : mp){
            vector<int> temp = itr.second;
            if(temp.size() <= 1)continue;
            for(int i = 0;i<temp.size()-1;i++){
                for(int j = i+1;j<temp.size();j++){
                    if((temp[i]*temp[j])%k == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
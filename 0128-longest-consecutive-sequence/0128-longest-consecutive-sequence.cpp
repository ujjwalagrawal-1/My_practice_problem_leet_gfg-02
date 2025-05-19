class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi = 0;
        int prev = 1;
        for(auto itr : mp){
            if(mp.count(itr.first+1)){
                prev++;
            }
            else{
                prev = 1;
            }
            maxi = max(maxi,prev);
        }
        return maxi;
    }
};
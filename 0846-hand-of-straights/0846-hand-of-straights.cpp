class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        sort(nums.begin(), nums.end());
        if(nums.size()%k!=0){
            return false;
        }


        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(mpp[nums[i]]<=0){
                continue;
            }
            for(int j=nums[i] ; j<nums[i]+ k; j++){
                if(mpp[j]<=0){
                    return false;
                }
                
                    mpp[j]--;
                
            }
        }
        return true;
    }
};
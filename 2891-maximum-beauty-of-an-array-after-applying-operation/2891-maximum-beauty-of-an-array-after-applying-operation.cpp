class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0;
        int maxi = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            while(s < i && nums[s] + k < nums[i]-k){
                s+=1;
            }
            maxi = max(maxi,i - s + 1);
        }
        return maxi;
    }
};
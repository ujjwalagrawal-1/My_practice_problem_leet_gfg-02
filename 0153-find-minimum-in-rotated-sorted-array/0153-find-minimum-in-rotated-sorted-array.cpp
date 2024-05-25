class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size();
        int mid = s +(e-s)/2;
        int ans = -1 ;
        while(s<=e){
            if(mid-1>0 && nums[mid-1]>nums[mid]){
                ans = mid-1;
            }
            if(mid+1<nums.size() && nums[mid+1]<nums[mid]){
                ans = mid;
            }
            if(nums[s]>=nums[mid]){
                e=mid-1;
            }
            else{
                s=mid;
            }
            mid = s + (e-s)/2;
        }
        if(ans+1>=nums.size())return nums[0];
        return nums[ans+1];
    }
};
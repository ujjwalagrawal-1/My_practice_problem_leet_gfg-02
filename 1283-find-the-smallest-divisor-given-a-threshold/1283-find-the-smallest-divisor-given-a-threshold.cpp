class Solution {
public:
bool check(vector<int> &nums, int t, int mid){
    int count=0;
    for(int i=0;i<nums.size();i++){
         count+=ceil((double)nums[i]/(double)mid);
    }
    return count<=t;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1,end=INT_MIN;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            end=max(end,nums[i]);
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(nums,threshold,mid)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};
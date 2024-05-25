class Solution {
public:
    bool search(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size() - 1;
        
        int mid = s + (e - s)/2;
        while(s<=e){
            int element  = nums[mid];
            if(target == element)
            return 1;
            else if(element >= target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e - s)/2;
        }
        return 0;
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        if(nums.size() == 1){
            return nums[0];
        }
        while(s <= e){
            int mid = s + (e - s)/2;
            if(mid == 0 || mid == nums.size()-1){
                return nums[mid];
            }
            if(nums[mid] != nums[mid-1] && nums[mid+1] != nums[mid]){
                return nums[mid];
            }
            if(nums[mid] == nums[mid-1]){
                if((nums.size()-1 - mid)%2 == 0){
                    e = mid - 2;
                }
                else{
                    s = mid + 1;
                }
            }
            if(nums[mid] == nums[mid + 1]){
                if((mid)%2 == 0){
                    s = mid+2;
                }
                else{
                    e = mid - 1;
                }
            }
        }

        return 0;

    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size();
        int mid = 0;
        while(s <= e){
            mid = s + (e - s)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid- 1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;int j = 0;
        while( i<nums.size()&&nums[i] != 0){
            i++;
        }
        j = i;
        while( j<nums.size() && nums[j] == 0  ){
            j++;
        }
        while(j  < nums.size()){
            swap(nums[i],nums[j]);
            i++;
            while( j  < nums.size() && nums[j] == 0 ){
             j++;
            }
        }
    }
};
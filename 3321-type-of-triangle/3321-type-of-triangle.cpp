class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        if(nums[0] == nums[1] && nums[1] == nums[2]){
            return "equilateral";
        }
        else if((nums[0] == nums[1] || (nums[1] == nums[2]) || nums[0] == nums[2]) && (a+b > c  && b+c > a &&  a+c > b)){
            return "isosceles";
        }
        else if((a+b > c  && b+c > a &&  a+c > b)) return "scalene"; else return "none";
    }
};
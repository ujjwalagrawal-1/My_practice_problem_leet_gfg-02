#define ll long long
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ll xoro = nums[0];
        for(int i = 1;i<nums.size();i++){
            xoro ^= nums[i];
        }
        int right = xoro ^ ( xoro&(xoro-1) );
        int num1 = 0,num2 = 0; 
        for(int i = 0;i<nums.size();i++){
            if((right&nums[i] ) != 0){
                num1 ^= nums[i];
            }
            else{
                num2 ^= nums[i];
            }
        }
        return {num1,num2};
    }
};
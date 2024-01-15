class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // First Approch
        // int pro1 = nums[0],pro2 = nums[0],result = nums[0];

        // for(int i = 1;i<nums.size();i++){
        //     int temp = max({nums[i],nums[i]*pro1,nums[i]*pro2});
        //     pro2 = min({nums[i],nums[i]*pro1,nums[i]*pro2});
        //     pro1 = temp;
        //     result = max(result,pro1);
        // }
        // return result;

        // Second Approch
        int result = nums[0];
        int temp = nums[0];
        bool flag = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == 0){
                temp = 1;
                flag = 1;
            }
            else{
                cout<<"temp is     "<<temp<<endl;
             temp *= nums[i];
            result = max(temp,result);
            }
        }
        if(flag){
            result = max(0,result);
        }
        return result;
    }
};
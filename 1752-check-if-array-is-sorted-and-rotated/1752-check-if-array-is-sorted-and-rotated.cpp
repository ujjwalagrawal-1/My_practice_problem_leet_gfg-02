class Solution {
public:
    bool check(vector<int>& nums) {
        int ind = nums.size()-1,mini = nums[0];
        for(int i = nums.size()-1;i>=1;i--){
           if(nums[i]>=nums[i-1]){
               ind = i-1;
           }
           else{
               break;
           }
        }
        int i = 0;
        while(i < nums.size()-1){
            // cout<<(i+ind)%nums.size()<<endl;
            if(nums[(i+ind)%nums.size()] > nums[(i+ind+1)%nums.size()]){
                // cout<<"yes"<<endl;
                return false;
            }
            i++;
        }
        return true;

    }
};
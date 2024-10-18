class Solution {
public:
int f(vector<int> & nums,int i,int tar,int curr){
    if(i >= nums.size()){
        if(curr == tar){
            return 1;
        }
        else{
            return 0;
        }
    }
    int ans = f(nums,i+1,tar,curr|nums[i]);
    ans += f(nums,i+1,tar,curr);

    return ans;
}
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0;
        int maxor = 0;
        for(int i = 0;i<nums.size();i++){
            maxor |= nums[i];
        }
        return f(nums,0,maxor,0);
    }
};
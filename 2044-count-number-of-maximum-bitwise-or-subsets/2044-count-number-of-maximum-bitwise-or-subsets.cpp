class Solution {
public:
int solve(vector<int> &veci,int i,int k,int curr){
    if(i >= veci.size()){
        if(curr == k){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int ans = 0;
    ans += solve(veci,i+1,k,curr|veci[i]);
    ans += solve(veci,i+1,k,curr);

    return ans;
}
    int countMaxOrSubsets(vector<int>& nums) {
        int k = 0;
        for(int i = 0;i<nums.size();i++){
            k |= nums[i];cout<<k<<endl;
        }
        return solve(nums,0,k,0);
    }
};
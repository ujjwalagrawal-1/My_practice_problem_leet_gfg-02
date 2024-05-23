class Solution {
public:
unordered_map<int,int> mp;
int f(vector<int> &nums,int &k,int ind){
    if(ind >= nums.size()){
        return 1;
    }
    int tk = 0,nt = 0;
    if(!mp.count(nums[ind] - k)){
        mp[nums[ind]]++;
        tk = f(nums,k,ind+1);
        mp[nums[ind]]--;
        if(mp[nums[ind]] == 0){
            mp.erase(nums[ind]);
        }
    }
    nt = f(nums,k,ind+1);

    return tk + nt;
}
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return f(nums,k,0)-1;
    }
};
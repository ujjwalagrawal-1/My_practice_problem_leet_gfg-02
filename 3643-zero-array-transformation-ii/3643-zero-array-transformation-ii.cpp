class Solution {
public:
bool f(int mid,vector<int> & nums,vector<vector<int>> & q){
    vector<int> veci(nums.size()+1,0);
    for(int i = 0;i < mid;i++){
        veci[q[i][0]] += q[i][2];
        veci[q[i][1]+1] -= q[i][2];
    }
    if(nums[0] - veci[0] > 0){
        return 0;
    }
    int i = 1;
    while(i<nums.size()){
        veci[i] += veci[i-1];
        if(nums[i] - veci[i] > 0){
            return 0;
        }
        i++;
    }
    return 1;
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int s = 0;
        int e = queries.size();
        bool fl = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(f(mid,nums,queries)){
                fl = 1;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        if(fl)return s;
        return -1;
    }
};
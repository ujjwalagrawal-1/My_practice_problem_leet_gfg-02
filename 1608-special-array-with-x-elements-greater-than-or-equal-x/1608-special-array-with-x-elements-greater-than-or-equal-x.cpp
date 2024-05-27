class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        for(int i=1;i<=n;i++){
            for(int j=0;j<n;j++){
                if(nums[j]>=i){
                    if(i==n-j)return i;
                    if(i<n-j)break;
                }
            }
        }

        return -1;
    }
};

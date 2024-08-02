class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1){
                cnt++;
            }
        }
        int k = cnt;
        int i = 0;
        while(k--){
            nums.push_back(nums[i]);
            i++;
        }
        int mini  = INT_MAX;
        int zero = 0;
        k = cnt;
        i = 0;int j = 0;
        while(j<nums.size()){
            if(nums[j] == 0){
                zero++;
            }
            if(j-i+1 > k){
                if(nums[i] == 0){
                    zero--;
                }
                i++;
            }
            if(j-i+1 == k){
                mini = min(mini,zero);
            }
            j++;
        }
        return mini ;
    }
};
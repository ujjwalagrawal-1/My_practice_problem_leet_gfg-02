class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<=3){
            return {};
        }
        vector<vector<int>> veci;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-3;i++){
            for(long long j = i+1;j<nums.size()-2;j++){
                long long k = j+1;
                long long l = nums.size()-1;
                while(k<l){
                    long long val = (long long)nums[i] +(long long) nums[j] +(long long) nums[k] +(long long) nums[l];
                    if( val == (long long)target){
                        st.insert({nums[i] ,nums[j] ,nums[k], nums[l]});
                        k++,l--;
                    }
                    else if(val>target){
                        l--;
                    }
                    else if(val<target){
                        k++;
                    }
                }
            }
        }
        for(auto itr:st){
            veci.push_back(itr);
        }
        return veci;
    }
};
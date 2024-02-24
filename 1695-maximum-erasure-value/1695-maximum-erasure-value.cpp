class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // So Question is Clear Indicating that we have to find Sub array with Unique elemnts and
        //  out of which we have to retunr out the maximum sum out of the unique element subarray
        int i = 0;
        int j = 0;
        int cs = 0;
        int ans = 0;
        set<int> st;
        while(j<nums.size()){
            if(st.count(nums[j]) == 0){
                st.insert(nums[j]);
                cs += nums[j];
                ans = max(ans,cs);
                j++;
            }
            else{
                while(st.count(nums[j]) != 0){
                    cs -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }
        return ans;
    }
};
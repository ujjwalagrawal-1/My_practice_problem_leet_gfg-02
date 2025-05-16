class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            int cnt = 0;
            vector<int> veci;
            for(int j = i;j<nums.size();j++){
                if(nums[j]%p == 0)cnt++;
                if(cnt > k){
                    break;
                }
                veci.push_back(nums[j]);
                st.insert(veci);
            }
        }
        return st.size();
    }
};
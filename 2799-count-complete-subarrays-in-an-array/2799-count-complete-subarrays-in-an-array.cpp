class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        for(int i = 0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        unordered_map<int,int> mp;
        int ans = 0;
        int uni = st.size();
        int i = 0;int j = 0;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size() == st.size()){
                ans += (nums.size()-j);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
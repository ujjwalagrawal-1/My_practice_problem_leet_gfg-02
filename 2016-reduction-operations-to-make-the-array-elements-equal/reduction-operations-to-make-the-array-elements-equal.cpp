class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto i:nums) freq[i]++;
        set<int> temp(nums.begin(),nums.end());
        vector<int> temp2(temp.begin(),temp.end());
        int count = 0;
        for(int i = temp2.size()-1;i>=1;i--){
            int elemFreq = freq[temp2[i]];
            int curr = elemFreq*i;
            count += curr;
        }
        return count;
    }
};
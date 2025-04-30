class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto& itr : nums){
            if(int(log10(itr)+1)%2 == 0){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> hash;
        int ele = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums[i].size();j++){
                int sum = i+j;
                hash[sum].push_back(nums[i][j]);
                ele++;
            }
        }

        vector<int> answer(ele);int index = 0;
        for(auto itr:hash){
            vector<int> ram = itr.second;
            for(int j = ram.size()-1;j>=0;j--){
                answer[index++] = ram[j];
            }
        }
        return answer;
    }
};
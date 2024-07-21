// class Solution {
// public:
//     std::vector<int> find_the_index(std::vector<int>& nums, int target, int i, int j) {
//         std::vector<int> index;
//         while ((i >= 0 && j < nums.size()) && (nums[i] + nums[j] <= target)) {
//             if (i == j) {
//                 i--;
//                 j++;
//                 continue;
//             }
//             if (nums[i] + nums[j] == target) {
//                 index.push_back(i);
//                 index.push_back(j);
//                 break;
//             }
//             i--;
//             j++;
//         }
//         return index;
//     }

//     std::vector<int> twoSum(std::vector<int>& nums, int target) {
//         std::vector<int> index;
//         for (int i = 0; i < nums.size(); i++) {
//             index = find_the_index(nums, target, i, i);
//             if (index.size() == 2) {
//                 break;
//             }
//             index = find_the_index(nums, target, i, i + 1);
//             if (index.size() == 2) {
//                 break;
//             }
//         }
//         return index;
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            for(int j = nums.size()-1;j>i;j--){
                // if()
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};

//another optimal solution

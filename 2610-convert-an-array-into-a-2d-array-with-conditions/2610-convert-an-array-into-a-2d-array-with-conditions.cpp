class Solution {
public:
// void solve(vector<int>& nums,int &i,vector<vector<int>> &answer){
//         if(i>=nums.size()){
//             return;
//         }
//         vector<int> ans;
//         unordered_map<int,int> mp;
//         // set<int> s;
//         while(mp[nums[i]] == 0 && i<nums.size() /*s.find(nums[i]) == s.end() && i<nums.size() */){
//             ans.push_back(nums[i]);
//             // s.insert(nums[i]);
//             mp[nums[i]]++;
//             i++;
//         }
//         answer.push_back(ans);
//         solve(nums,i,answer);
// }
    vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>> answer;
    unordered_map<int, int> mp;

    for (auto itr : nums) {
        mp[itr]++;
    }

    while (!mp.empty()) {
        vector<int> ans;
        for (auto itr = mp.begin(); itr != mp.end();) {
            ans.push_back(itr->first);
            (itr->second)--;

            if (itr->second == 0) {
                itr = mp.erase(itr);
            } else {
                ++itr;
            }
        }
        answer.push_back(ans);
    }

    return answer;
}

};
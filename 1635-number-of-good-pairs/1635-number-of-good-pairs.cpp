class Solution {
public:
// int bsindex(vector<pair<int,int>> &veci,int target){
//     int s = 0;
//     int e = veci.size()-1;
//     int mid = s + (e - s)/2;
//     int ans = -1;
//     while(s<=e){
//         if(veci[mid].first == target){
//             ans = veci[mid].second;
//             return ans;
//         }
//         else if(veci[mid].first > target){
//             e = mid - 1;
//         }
//         else{
//             s = mid + 1;
//         }
//         mid = s + (e - s)/2;
//     }
//     return ans;
// }
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> hash;

        for(auto itr:nums){
            hash[itr]++;
        }

        int count = 0;

        for(auto itr:hash){
            int n = itr.second; 
            count += n*(n-1)/2;
        }
        return count;
    }
};
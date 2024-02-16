class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto itr:arr){
            mp[itr]++;
        }
        arr.clear();
        for(auto itr:mp){
            arr.push_back(itr.second);
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
        int t = 0;
        int i = 0;
        while(i<arr.size()){
            t += arr[i];
            if(t>k){
               break;
            }
            if(t <= k){
                ans++;
            }
            i++;
        }
        return (arr.size() - ans); 
    }
};
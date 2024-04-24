class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> max_arr(arr.size());
        vector<int> min_arr(arr.size());
        int maxi = INT_MIN;
        for(int i = 0;i<arr.size();i++){
            max_arr[i] = max(maxi,arr[i]);
        }
        int mini = INT_MAX;
        for(int i = arr.size()-1;i>=0;i--){
            min_arr[i] = min(mini,arr[i]);
        }
        int ans = 0;
        for(int i = 0;i<arr.size()-1;i++){
            if(max_arr[i] <= min_arr[i+1])ans++;
        }

        return ans+1;
    }
};
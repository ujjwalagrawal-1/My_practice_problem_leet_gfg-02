class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxi = arr[0];
        int ans = 0;
        for(int i  = 0;i<arr.size();i++){
            maxi = max(maxi,arr[i]);
            if(maxi == i){
                ans++;
            }
        }
        return ans;

    }
};
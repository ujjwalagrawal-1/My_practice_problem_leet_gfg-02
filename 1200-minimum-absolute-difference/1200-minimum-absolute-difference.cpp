class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> veci;
        int mini = INT_MAX;
        for(int i = 1;i<arr.size();i++){
            if(mini > (arr[i] - arr[i-1])){
                while(veci.size()){
                    veci.pop_back();
                }
                mini = arr[i] - arr[i-1];
            }
            if(mini == arr[i] - arr[i-1]){
                veci.push_back({arr[i-1],arr[i]});
            }
        }
        return veci;
    }
};
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> ans(arr.size()+1,0);
        for(int i = 0;i<arr.size();i++){
            ans[i+1] = arr[i]^ans[i];
        }
        int rep = 0;
        for(int i = 0;i<arr.size();i++){
            for(int k = i+1;k<arr.size();k++){
                if((ans[k+1] == ans[i])){
                    rep += k-i;
                }
            }
        }
        return rep;
    }
};
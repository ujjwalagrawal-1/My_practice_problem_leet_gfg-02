class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        if(n == 1){
            return arr[0];
        }
        int per = n/4;
        int cou = 1;
        for(int i = 0;i<n-1;i++){
            if(arr[i] == arr[i+1]){
                cou++;
            }
            if(cou>per){
                return arr[i];
            }
            if(arr[i] != arr[i+1]){
                cou = 1;
            }
        }
        return 0;
    }
};
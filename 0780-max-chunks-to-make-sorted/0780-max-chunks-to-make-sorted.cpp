class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt = 0;
        int prev = -1;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] != i){
                int val = arr[i];
                while(i <= val){
                    if(arr[i] > val){
                        val = arr[i];
                    }
                    i++;
                }
                cnt++;i--;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};
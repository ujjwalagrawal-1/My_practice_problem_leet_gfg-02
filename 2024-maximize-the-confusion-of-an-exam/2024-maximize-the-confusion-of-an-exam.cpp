class Solution {
public:
    int maxConsecutiveAnswers(string arr, int k) {
        int i = 0;int j = 0;
        int ct = 0,cf = 0;
        int maxi = -1;
        while(j<arr.size()){
            if(arr[j] == 'T'){
                ct++;
            }
            else{
                cf++;
            }
            if(ct <= k || cf <= k)maxi = max(maxi,j-i+1);
            else{
                if(arr[i++] == 'T')ct--;
                else{
                    cf--;
                }
            }
            j++;
        }
        return maxi;
    }
};
class Solution {
public:
    int minSwaps(string s) {
        int i = 0;
        int maxi = 0;
        int maxiclose = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '['){
                maxiclose--;
            }
            else{
                maxiclose++;
            }
            maxi = max(maxi,maxiclose);
        }
        return (maxi+1)/2;
    }
};
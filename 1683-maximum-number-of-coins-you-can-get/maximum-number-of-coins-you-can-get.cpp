class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int sum = 0;
        int i = 0;int j = piles.size()-1;
        while(i<=j){
            j--;
            sum += piles[j];
            j--;i++;
        }
        return sum;
    }
};
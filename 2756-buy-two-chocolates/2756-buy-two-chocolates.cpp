class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int ans = money ;
        sort(prices.begin() , prices.end()) ;
        for(int i=0; i<2; i++){
           ans -= prices[i] ;
        }
        if(ans < 0)ans = money ;
        return ans ;
    }
};
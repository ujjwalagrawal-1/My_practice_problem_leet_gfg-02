class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        //Second Approch is by finding two minimum element in the array;

        int first = INT_MIN;
        int second = INT_MIN;
        if(prices[0]<=prices[1]){
            first = prices[0];
            second = prices[1];
        }
        else{
            first = prices[1];
            second = prices[0];
        }
        for(int i = 2;i<prices.size();i++){
            if(prices[i]<=first){
                second = first;
                first = prices[i];
            }
            else if(prices[i]<second){
                second = prices[i];
            }
        }
        // cout<<first<<" "<<second<<endl;
        if(first+second <= money){
            return money - (first+second);
        }
        else{
            return money;
        }
    }
};
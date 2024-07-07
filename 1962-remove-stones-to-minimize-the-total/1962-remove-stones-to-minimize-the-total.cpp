class Solution {
public:

    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto itr:piles){
            sum += itr;
            pq.push(itr);
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(pq.size() != 0){
            sum -= (pq.top()/2);
            pq.pop();
        }
        return sum;
    }
};
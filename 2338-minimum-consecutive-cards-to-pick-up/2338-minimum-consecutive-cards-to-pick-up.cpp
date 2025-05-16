class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int mini = cards.size()+1;
        map<int,int> mp;
        for(int i = 0;i<cards.size();i++){
            if(mp.count(cards[i])){
                mini = min(mini, i +1 - mp[cards[i]]);
            }
            mp[cards[i]] = i;
        }
        return mini > cards.size() ? -1 : mini;
    }
};
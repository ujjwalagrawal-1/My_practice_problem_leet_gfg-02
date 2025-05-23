class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()<2){
            return fruits.size();
        }
        int s = 0;
        int e = 0;
        int n = fruits.size(); 
        int maxi = -1;
        unordered_map<int,int> mp;
        while(e<n){
            mp[fruits[e]]++;
            if(mp.size() > 2){
                while(mp.size() != 2){
                    mp[fruits[s]]--;
                    if(mp[fruits[s]] == 0){
                        mp.erase(fruits[s]);
                    }
                    s++;
                }
            }
            maxi = max(maxi,e-s+1);
            e++;
        }
        return maxi;
    }
};
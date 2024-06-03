class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto it: tasks){
            mp[it]++;
        }
        int ans = 0;
        bool flag = true;
        for(auto it: mp){
            int x = it.second;
            if(x == 1){
                flag = false;
                break;
            }
            ans+=x/3;
            if(x%3>0){
                ans++;
            }
        }
        if(!flag){
            return -1;
        }
        return ans;
    }
};
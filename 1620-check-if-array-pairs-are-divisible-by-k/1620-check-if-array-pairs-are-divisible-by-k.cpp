class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i = 0;i<arr.size();i++){
            mp[(arr[i]%k + k)%k]++;
        }
        int ans = 0;
        for (auto itr : mp){
            int rem = itr.first;
            if (rem == 0) {
                if(mp[rem] % 2 != 0) return false;
            }
            else if(2 * rem == k) {
                if (mp[rem] % 2 != 0) return false;
            }
            else{
                if (mp[rem] != mp[k - rem]) return false;
            }
        }

        return true;
    }
};
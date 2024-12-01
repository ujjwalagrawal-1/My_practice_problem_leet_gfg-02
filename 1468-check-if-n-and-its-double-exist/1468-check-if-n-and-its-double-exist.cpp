class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto itr : arr){
            if(itr == 0){
                if(mp[itr]>1){
                    return 1;
                }
            }
            else if(mp[itr*2] > 0){
                return true;
            }
        }
        return false;
    }
};
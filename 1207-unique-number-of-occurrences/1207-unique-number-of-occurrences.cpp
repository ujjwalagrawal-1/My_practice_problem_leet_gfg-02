class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>hash;
        for(auto itr:arr){
            hash[itr]++;
        }
        unordered_map<int,int>hash_sec;
        for(auto itr:hash){
            hash_sec[itr.second]++;
        }
        for(auto itr : hash_sec){
            if(itr.second>1){
                return false;
            }
        }
        return true;
    }
};
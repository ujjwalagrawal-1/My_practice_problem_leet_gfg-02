class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> hash;
        for(auto itr:word){
                hash[itr]++;
        }
        int ans = 0;
        int count = 0;int y = 0;
        vector<int> veci;
        for(auto itr:hash){
            veci.push_back(itr.second);
        }
        sort(veci.begin(),veci.end());
        for(int i = veci.size()-1;i>=0;i--){
                if(y%8 == 0){
                count++;
                }
                
                ans += count*veci[i];y++;  
        }
            return ans;
        
        
    }
};
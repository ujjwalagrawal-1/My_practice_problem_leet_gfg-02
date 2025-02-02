class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> veci(4);
        int ans=  0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'N'){
                veci[0]++;
            }
            if(s[i] == 'S'){
                veci[1]++;
            }
            if(s[i] == 'E'){
                veci[2]++;
            }
            if(s[i] == 'W'){
                veci[3]++;
            }
            int maxi = max(veci[0],veci[1]) + max(veci[2],veci[3]);
            int mini = min(veci[0],veci[1]) + min(veci[2],veci[3]);
            ans = max(ans,maxi-mini  + 2*min(mini,k));
        }
        return ans;
    }
};
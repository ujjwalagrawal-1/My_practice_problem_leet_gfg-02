class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        map<string,int> a,b;
        for(int i = 0;i<w.size();i++){
            if(w[i][0] == w[i][1]){
                b[w[i]]++;
            }
            else{
                a[w[i]]++;
            }
        }
        int cnt = 0;
        for(auto i : a){
            string rev = i.first;
            reverse(rev.begin(),rev.end());
            if(a.count(rev)){
                cnt += min(i.second,a[rev])*2;
                a.erase(rev);
            }
        }
        bool fl = 0;
        for(auto i : b){
            if(i.second&1)fl = 1;
            cnt += i.second&1 ? i.second - 1 : i.second;
        }
        if(fl)cnt++;
        return cnt*2;
    }
};

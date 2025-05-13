class Solution {
public:
    static bool comp(vector<int> & a ,vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),comp);
        int cnt = 0;
        for(int i = 0;i<p.size()-1;i++){
            int y = INT_MIN;
            for(int j = i+1;j<p.size();j++){
                if(p[i][1] >= p[j][1]){
                    // cout<<"yes for i , j "<<i<<" "<<j<<endl;
                    if(y < p[j][1]){
                        // cout<<"no for i , j "<<i<<" "<<j<<endl;
                        cnt++;
                    }
                    y = max(y,p[j][1]);
                }
            }
        }
        return cnt;
    }
};
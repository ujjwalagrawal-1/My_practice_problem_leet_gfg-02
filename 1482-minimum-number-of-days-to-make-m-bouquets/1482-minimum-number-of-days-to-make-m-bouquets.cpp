class Solution {
public:
bool f(vector<int> & bd,int m,int k,int days){
    int cnt = 0;
    int bas = 0;
    for(int i = 0;i<bd.size();i++){
        if(bd[i] <= days){
            cnt++;
        }
        else{
            bas += (cnt/k);
            cnt = 0;
        }
    }
    bas += (cnt/k);
    return bas >= m;
}
    int minDays(vector<int>& bd, int m, int k) {
        int s = INT_MAX;
        int e = INT_MIN;
        if(bd.size() < 1LL*k*m*1LL){
            return -1;
        }
        for(int i = 0;i<bd.size();i++){
            s = min(s,bd[i]);
            e = max(e,bd[i]);
        }
        int ans = 0;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(f(bd,m,k,mid)){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return e+1;
    }
};
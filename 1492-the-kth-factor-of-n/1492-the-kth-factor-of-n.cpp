class Solution {
public:
vector<int> factors(int n){
    vector<int> ans;
    for(int i = 1;i*i<=n;i++){
        if(n%i == 0){
            ans.push_back(i);
            if(n/i != i){
                ans.push_back(n/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
    int kthFactor(int n, int k) {

        vector<int> ans = factors(n);

        if(ans.size() < k){
            return -1;
        }
        else{
            return ans[k-1];
        }
    }
};
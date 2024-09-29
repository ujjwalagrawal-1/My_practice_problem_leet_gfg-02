class Solution {
public:
bool is(char &ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return 1;
    }
    return 0;
}

int chk(vector<int> &f,int k){
    int cnt = 0;
    bool fl = 0;
    if(f['a' - 'a'] > 0 && f['e' - 'a'] > 0 && f['i' - 'a'] > 0 && f['o' - 'a'] > 0 && f['u' - 'a'] > 0){
        fl = 1;
    }
    for(int i = 0;i<26;i++){
        if(f[i] > 0){
            if(i == int('a' - 'a') || i == int('e' - 'a') || i == int('i' - 'a') || i == int('o' - 'a') || i == int('u' - 'a')){
            }
            else{
                cnt += f[i];
            }
        }
    }
        if(fl && cnt == k){
            // cout<<"1 is out  "<<endl;
            return 1;
        }
        if(fl && cnt > k){
            // cout<<"2 is out "<<endl;
            return 2;
        }
        return 0;
}
    long long countOfSubstrings(string w, int k) {
        long long ans = 0;
        int n = w.size();
        vector<int> veci(n,n);
        int lc = n;
        for(int i = n-1;i >= 0;i--){
            veci[i] = lc;
            if(!is(w[i])){
                lc = i;
            }
        }
        vector<int> f(26,0);
        int i = 0,j = 0;
        while(j < veci.size()){
            f[w[j] - 'a']++;
            int val = chk(f,k);
            while(i <= j && val >= 1){
                if(val == 1){
                    ans += (veci[j] - j);
                    f[w[i] - 'a']--;
                    i++;
                    val = chk(f,k);
                }
                else{
                    f[w[i] - 'a']--;
                    i++;
                    val = chk(f,k);
                }
            }
            j++;
        }
        return ans;
    }
};
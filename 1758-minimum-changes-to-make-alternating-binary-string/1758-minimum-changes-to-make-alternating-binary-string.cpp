// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef vector<vi> vvi;
// typedef vector<vll> vvll;
// typedef vector<pair<int,int>> vpii;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
class Solution {
public:
int solve(string s){
    int ope = 0;
    int n = s.size();
        if(n%2 == 0){
        for(int i = 0;i < n-1;){
            if(s[0] == '1' && (s[i] != '1' || s[i+1] == '1')){
                if(s[i] != '1'){
                    // cout<<"type"<<endl;
                    ope++;
                }
                if(s[i+1] == '1'){
                    ope++;
                }
            }
            else if(s[0] == '0' && (s[i] != '0' || s[i+1] != '1')){
                if(s[i] != '0'){
                    ope++;
                }
                if(s[i+1] == '0'){
                    ope++;
                }
            }
            i += 2;
        }
        // cout<<"final is -->"<<ope<<endl;
        }
        else{
            for(int i = 0;i < n-2;){
            if(s[0] == '1' && (s[i] != '1' || s[i+1] == '1')){
                if(s[i] != '1'){
                    // cout<<"type"<<endl;
                    ope++;
                }
                if(s[i+1] == '1'){
                    ope++;
                }
            }
            else if(s[0] == '0' && (s[i] != '0' || s[i+1] != '1')){
                if(s[i] != '0'){
                    ope++;
                }
                if(s[i+1] == '0'){
                    ope++;
                }
            }
            i += 2;
        }
        // cout<<"final is -->"<<ope<<endl;
        ope += s[n-1] == s[0] ? 0:1;
        }
        return ope;
}
    int minOperations(string s) {
        int n = s.size(); 
        if(n<=1){
            return 0; 
        }
        int x = solve(s);
        s[0] = s[0] == '0'? '1' : '0';
        int y = solve(s);
        // cout<<x<<"  "<<y;
        
    return x>y+1?y+1:x;
    }
};
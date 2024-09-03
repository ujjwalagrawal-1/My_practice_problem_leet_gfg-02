class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for(int  i = 0;i<s.size();i++){
            int num = int(s[i]-'a')+1;
            // cout<<num<<endl;
            while(num){
                ans += num%10;
                num /= 10;

            }
        }
        k--;
        while(k){
            int num = ans;
            ans = 0;
            while(num){
                ans += num%10;
                num /= 10;
            }
            if(ans == 0){
                return 0;
            }
            k--;
        }
        return ans;
    }
};
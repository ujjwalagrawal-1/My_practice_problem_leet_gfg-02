class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size());
        for(int i = 0;i<code.size();i++){
            int j = i+1;
            int cnt = 0;
            int sum = 0;
            if(k > 0){
                int j = i+1;
                while(cnt < k){
                    cnt++;
                    sum += code[j%code.size()];
                    j++;
                }
            }
            if(k < 0){
                int j = i-1;
                while(cnt > k){
                    if(j<0){
                        j += code.size();
                    }
                    cnt--;
                    sum += code[j%code.size()];
                    j--;
                }
            }

            ans[i] = sum;
        }

        return ans;
    }
};
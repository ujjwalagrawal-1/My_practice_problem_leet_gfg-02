class Solution {
public:
    char kthCharacter(int k) {
        string t = "a";
        while(t.size() < k){
            int p = t.size();
            for(int i = 0;i < p;i++){
                if(t[i] == 'z'){
                    t += 'a';
                }
                else{
                    t += char(t[i] + 1);
                }
            }
        }

        return t[k-1];
    }
};
class Solution {
public:
    int maxScore(string s) {
        int val = 0;
        int countone = 0; 
        int countzero = 0; 
        int i = s.size()-1;
        while(i>=0){
            if(s[i] == '1'){
                countone++;
            }
            i--;
        }
        cout<<countone<<endl;
        int g;
        for(int i = 0;i<s.size()-1;i++){
            if(s[i] == '0'){
                countzero++;
            }
            else{
                countone--;
            }
            val = max(val,countzero+countone);
        }
        return val;
    }
};
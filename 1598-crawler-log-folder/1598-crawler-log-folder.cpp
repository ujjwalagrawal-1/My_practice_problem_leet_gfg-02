class Solution {
public:
    int minOperations(vector<string>& logs) {
        int a = 0;
        for(int i = 0; i < logs.size(); i++){
            string tp = logs[i];
            if(tp == "../") {
                if(a > 0) a--;
            }
            else if(tp == "./") {
                
            }
            else {
                a++;
            }
        }
        return a;
    }
};

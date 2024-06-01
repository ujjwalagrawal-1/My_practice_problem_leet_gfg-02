class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& se, int time) {
        vector<int> answer;
        vector<int> forword(se.size(),0);
        vector<int> backword(se.size(),0);
        int postcal = 0;
        for(int i = 1;i<se.size();i++){
            if(se[i-1] >= se[i]){
                postcal++;
            }
            else{
                postcal = 0;
            }
            forword[i] = postcal;
        }
        postcal = 0;
        for(int i = se.size()-2;i>=0;i--){
            if(se[i+1] >= se[i]){
                postcal++;
            }
            else{
                postcal = 0;
            }
            backword[i] = postcal;
        }
        for(int i = 0;i<se.size();i++){
            if(time <= forword[i] && time <= backword[i]){
                answer.push_back(i);
            }
        }
        return answer;
    }
};
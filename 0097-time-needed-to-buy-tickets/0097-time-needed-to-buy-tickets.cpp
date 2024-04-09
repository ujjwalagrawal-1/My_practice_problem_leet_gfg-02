class Solution {
public:
    int timeRequiredToBuy(vector<int>& tkts, int k) {
        int count = 0;
        while(tkts[k]) {
            for(int i=0; i<tkts.size(); i++) {
                if(tkts[i] == 0) continue;
                tkts[i]--;
                count++;
                if(tkts[k] == 0) break;
            }
        }
        return count;
    }
};
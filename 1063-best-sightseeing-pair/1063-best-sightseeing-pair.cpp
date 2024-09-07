class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int maxScore = INT_MIN;
        int best = val[0];
        for (int i = 1; i < val.size(); i++) {
            maxScore = max(maxScore, best + val[i] - i);
            best = max(best, val[i] + i);
        }
        return maxScore;
    }
};

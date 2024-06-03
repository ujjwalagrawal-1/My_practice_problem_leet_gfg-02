class Solution {
public:
bool isPossible(vector<int> &weights, int days, int maxWeight) {
        int currentWeight = 0;
        int daysNeeded = 1; // Start with one day

        for (int weight : weights) {
            if (currentWeight + weight > maxWeight) {
                daysNeeded++;
                currentWeight = weight;
                if (daysNeeded > days) {
                    return false;
                }
            } else {
                currentWeight += weight;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& w, int days) {
        int e = 0;
        int i = 0;
        int s = INT_MIN;
        while(i<w.size()){
            e += w[i];
            s = max(w[i],s);i++;
        }
        while(s < e){
            int mid = s + (e - s)/2;
            if(isPossible(w,days,mid)){
                e  = mid;
            }
            else{
                s = mid + 1;
            }
        }
        return s;
    }
};
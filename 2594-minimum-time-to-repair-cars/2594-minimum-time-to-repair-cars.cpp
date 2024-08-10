class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long int start = 1, end = 1e14, ans = 0;
        while(start<=end){
            long long mid = start+(end-start)/2, carCount = 0;
            for(int i=0; i<ranks.size(); i++){
                carCount += sqrt(mid/ranks[i]);
            }
            if(carCount >= cars)
                ans = mid, end = mid-1;
            else
                start = mid+1;
        } 
        return ans;
    }
};
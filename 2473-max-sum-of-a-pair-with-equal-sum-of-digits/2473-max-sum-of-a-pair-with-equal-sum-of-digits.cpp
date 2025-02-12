class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> a;
        for(int i = 0;i<nums.size();i++){
            int sum = 0;
            int  t = nums[i];
            while(nums[i]){
                sum += nums[i]%10;
                nums[i]/=10;
            }
            a[sum].push_back(t);
        }
        int maxi = INT_MIN;
        for(auto itr : a){
            if(itr.second.size() <= 1){
                continue;
            }
            priority_queue<int,vector<int>,greater<int>> pq;
            for(auto i : itr.second){
                pq.push(i);
                if(pq.size() > 2){
                    pq.pop();
                }
            }
            int r = 0;
            while(pq.size() >0){
                r += pq.top();
                pq.pop();
            }
            maxi = max(maxi,r);
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};
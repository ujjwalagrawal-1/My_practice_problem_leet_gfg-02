class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> hp;
        // vector<int> ans;
        for(auto itr:nums){
            hp.push(itr);
        }
        int i  =0;
        while(hp.size()){
            nums[i] = (hp.top());
            hp.pop();
            i++;
        }

        return nums;
    }
};
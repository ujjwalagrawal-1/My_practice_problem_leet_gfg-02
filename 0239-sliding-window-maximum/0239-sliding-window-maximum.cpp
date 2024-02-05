class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> qu;
        vector<int> ans;
        int j = 0,i = 0;
        // qu.push(nums[0]);
        
        while(j<nums.size()){
            while(!qu.empty() && qu.back()<nums[j]){
                qu.pop_back();
            }
            qu.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1 == k){
                ans.push_back(qu.front());
                if(nums[i] == qu.front()){
                    qu.pop_front();
                }
                i++;
                j++;
            }

        }
        return ans;
    }
};
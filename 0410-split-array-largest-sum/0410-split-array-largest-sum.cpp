class Solution {
public:
int c(vector<int> &nums,int t,int k){
    int cnt = 1;
    int cc = 0;
    int maxi = INT_MIN;
    int i = 0;
    for(auto itr : nums){
        cc += itr;
        if(cc > t){
            if(i != nums.size()-1)
            cnt++;
            // cout<<"break  at cc = "<<cc<<endl;
            cc = itr;
        }
        if(cnt > k){
            return 0;
        }
        // cout<<"current cc is  "<<cc<<endl;
        maxi = max(maxi,cc);
    }
    // cout<<"maxi is "<<maxi<<endl;
    i++;
    return maxi;
}
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int s = 0; int e = sum;
        // cout<<"Sum is "<<sum<<endl;
        int ans = sum;
        while(s <= e){
            int mid = s + (e - s)/2;
            // cout<<"Mid is "<<mid<<endl;
            int val = c(nums,mid,k);
            if(val > 0){
                ans = val;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};
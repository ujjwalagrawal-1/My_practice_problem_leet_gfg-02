class Solution {
public:
   int find_ans(vector<int>&nums,int k,int i,unordered_map<int,int> &st){
     if(i<0)return 1;
    int take=0;
    int nottake=0;
      st[nums[i]]++;
    if(st[nums[i]+k]==0){
        take=find_ans(nums,k,i-1,st);
    }
        st[nums[i]]--;
        // if(st[nums[i]]==0)st.erase(nums[i]);
        nottake=find_ans(nums,k,i-1,st);
    
    return take+nottake;

   }
    int beautifulSubsets(vector<int>& nums, int k) {
        // first using recursion
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        return  find_ans(nums,k,n,mp)-1;
    }
};
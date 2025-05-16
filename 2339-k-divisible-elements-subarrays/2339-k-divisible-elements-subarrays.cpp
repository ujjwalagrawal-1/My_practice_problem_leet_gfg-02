struct node{
    map<int,node*> links;
};
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        node* root = new node();
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            node* temp = root;
            int cnt = 0;
            for(int j = i;j<nums.size();j++){
                if(nums[j]%p == 0)cnt++;
                if(cnt > k){
                    break;
                }
                if(temp->links[nums[j]] == NULL){
                    temp->links[nums[j]] = new node();
                    ans++;
                }
                temp = temp->links[nums[j]];
            }
        }
        return ans;
    }
};
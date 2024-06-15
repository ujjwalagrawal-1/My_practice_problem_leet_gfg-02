class Solution {
private:
    int closest(vector<int> veci,int t){
        int s = 0;
        int e = veci.size()-1;

        while(s <= e){
            int mid = s + (e - s)/2;

            if(veci[mid] <= t){
                s = mid + 1;
            }
            else{
                e = mid-1;
            }
        }
        return e;
    } 
    void inorder(TreeNode* root, vector<int>& bs) {
        if (!root) {
            return;
        }

        inorder(root->left, bs);

        bs.push_back(root->val);

        inorder(root->right, bs);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> bs;
        inorder(root, bs);
        vector<vector<int>> ans;
        for (auto it : queries) {
            vector<int> temp;
            int lower = lower_bound(bs.begin(), bs.end(), it) - bs.begin();
            int upper = closest(bs, it);

            if (upper < bs.size()) {
                temp.push_back(bs[upper]);
            } else {
                temp.push_back(-1);
            }
            if (lower < bs.size()) {
                temp.push_back(bs[lower]);
            } else {
                temp.push_back(-1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
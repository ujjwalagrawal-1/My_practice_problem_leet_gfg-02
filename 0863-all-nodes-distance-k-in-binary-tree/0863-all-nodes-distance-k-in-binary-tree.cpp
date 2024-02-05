class Solution {
public:
    void parent_to_child_mapping(TreeNode* &root, unordered_map<TreeNode*, TreeNode*>& hash) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr->left) {
            q.push(curr->left);
            hash[curr->left] = curr;
        }

        if (curr->right) {
            q.push(curr->right);
            hash[curr->right] = curr;
        }
    }
}


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> hash;
        parent_to_child_mapping(root, hash);

        queue<TreeNode*> store;
        store.push(target);
        unordered_map<TreeNode*, bool> check;
        check[target] = true;

        while (!store.empty() && k > 0) {
            int size = store.size();
            for (int i = 0; i < size; i++) {
                TreeNode* val = store.front();
                store.pop();

                if (hash.find(val) != hash.end() && !check[hash[val]]) {
                    store.push(hash[val]);
                    check[hash[val]] = true;
                }

                if (val->left && !check[val->left]) {
                    store.push(val->left);
                    check[val->left] = true;
                }

                if (val->right && !check[val->right]) {
                    store.push(val->right);
                    check[val->right] = true;
                }
            }

            k--;
        }

        vector<int> ans;
        while (!store.empty()) {
            TreeNode* q = store.front();
            ans.push_back(q->val);
            store.pop();
        }

        return ans;
    }
};

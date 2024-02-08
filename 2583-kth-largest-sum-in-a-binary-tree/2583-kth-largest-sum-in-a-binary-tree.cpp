/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode*& root, int& k) {
        queue<TreeNode*> qu;
        qu.push(root);
        vector<long long> ans;
        while (!qu.empty()) {
            int n = qu.size();
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = qu.front();
                sum += temp->val;
                qu.pop();
                if (temp->left)
                    qu.push(temp->left);
                if (temp->right)
                    qu.push(temp->right);
            }
            ans.push_back(sum);
        }
        if (ans.size() < k) {
            return -1;
        }
        sort(ans.begin(), ans.end());
        return ans[ans.size() - k];
    }
};
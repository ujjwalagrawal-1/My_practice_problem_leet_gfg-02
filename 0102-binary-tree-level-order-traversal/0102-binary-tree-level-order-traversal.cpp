/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL ){
            return  {};
        }
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> answer;
        while(!qu.empty()){
            int sz = qu.size();
            vector<int> temp;
            for(int i = 0;i<sz;i++){
                TreeNode* re = qu.front();
                qu.pop();
                temp.push_back(re->val);
                if(re->left){
                    qu.push(re->left);
                }
                if(re->right){
                    qu.push(re->right);
                }
            }
            answer.push_back(temp);
        }

        return answer;
    }
};
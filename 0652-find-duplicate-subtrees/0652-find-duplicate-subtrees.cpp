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
string solve(TreeNode* &root,unordered_map<string,int> &mp,vector<TreeNode*> &result){
    if(root == NULL){
        return "N";
    }
    string ans = to_string(root->val)+ "," + solve(root->left,mp,result) + "," + solve(root->right,mp,result);
    if(mp[ans] == 1 ){
        result.push_back(root);
    }
    mp[ans]++;
    return ans;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> result; 
        solve(root,mp,result);
        return result;
    }
};
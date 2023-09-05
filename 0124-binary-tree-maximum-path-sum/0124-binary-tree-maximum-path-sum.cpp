/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    int pathsum(TreeNode *root,int &maxi)
    {
        if (root == NULL){
            return 0;
        }
        int leftkaans = max(0,pathsum(root->left,maxi));
        int rightkaans =  max(0,pathsum(root->right,maxi));
        maxi = max(maxi,root->val+leftkaans+rightkaans);
        return root->val + max(leftkaans, rightkaans);
    }

    int maxPathSum(TreeNode *root) {
      int VAL = INT_MIN;
      pathsum(root,VAL);
      return VAL;
    }
};
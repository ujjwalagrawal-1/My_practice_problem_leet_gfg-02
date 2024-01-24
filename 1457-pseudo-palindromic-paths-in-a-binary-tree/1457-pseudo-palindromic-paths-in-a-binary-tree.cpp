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
void fun(TreeNode* &root,map<int,int> &hash,int &cnt){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        hash[root->val]++;
        bool flag = true;
        int oddCount = 0;
        for (auto itr : hash) {
            if (itr.second % 2 != 0) {
                oddCount++;
                if (oddCount > 1) {
                    flag = false;
                    break;
                }
            }
        }
        cnt += flag? 1:0;
        hash[root->val]--;
        return;
    }
    hash[root->val]++;
    fun(root->left,hash,cnt);
    fun(root->right,hash,cnt);
    hash[root->val]--;
}
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        map<int,int> hash;
        fun(root,hash,cnt);
        return cnt;
    }
};
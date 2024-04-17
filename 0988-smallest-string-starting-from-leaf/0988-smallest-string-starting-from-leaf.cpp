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
    
    void recu(TreeNode* root ,  string ans,string &minstring)
    {
        
        if(root==NULL)
        {
            return ;
        }
        if(root->left==NULL && root->right==NULL)
        {
            ans=(char)('a' + root->val) + ans;
           if(minstring!="")
           {
               minstring = min(minstring , ans);
           }
            else
            {
                minstring = ans;
            }
            return ;
        }
        
        ans = char('a'+ root->val) + ans;
        
        recu(root->left , ans ,minstring);
        recu(root->right , ans,minstring);
        
        return ;
    
    }
    string smallestFromLeaf(TreeNode* root) {
        string minstring = "";
        recu(root,"",minstring);
        return minstring;

    }
};
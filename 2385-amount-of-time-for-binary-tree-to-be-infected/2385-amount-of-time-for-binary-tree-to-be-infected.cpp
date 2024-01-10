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
 #define data val
class Solution {
public:
TreeNode* Nodeparent_tree(TreeNode* root,int target,unordered_map<TreeNode*,TreeNode*> &req_ump){
      TreeNode* Target_Node = nullptr;
      queue<TreeNode*> q;
      q.push(root);
      req_ump[root] = nullptr;
      
      while(!q.empty()){
          TreeNode* temp = q.front();q.pop(); 
          if(temp->data == target){
              Target_Node = temp;
          }
          if(temp->left){
              q.push(temp->left);
              req_ump[temp->left] = temp;
          }
          if(temp->right){
              q.push(temp->right);
              req_ump[temp->right] = temp;
          }
      }
      return Target_Node;
    }
    
    int answer_to_the_problem(TreeNode* Target_Node,unordered_map<TreeNode*,TreeNode*> &req_ump){
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> isburnt;
        q.push(Target_Node);
        int answer = 0;
        isburnt[Target_Node] = 1;
        while(!q.empty()){
            int lev = q.size();
            bool flag = 0;
            for(int i = 0;i < lev;i++){
                TreeNode* temp = q.front();q.pop();
                if(temp->left && !isburnt[temp->left]){
                    q.push(temp->left);
                    isburnt[temp->left] = 1;
                    flag = true;
                }
                if(temp->right && !isburnt[temp->right]){
                    q.push(temp->right);
                    isburnt[temp->right] = 1;
                    flag = true;
                }
                if(req_ump[temp] && !isburnt[req_ump[temp]]){
                    q.push(req_ump[temp]);
                    isburnt[req_ump[temp]] = 1;
                    flag = true;
                }
            }
            if(flag){
                ++answer;
            }
        }
        return answer;
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<TreeNode*,TreeNode*> req_ump;
        TreeNode* temp = Nodeparent_tree(root,start,req_ump);
        return answer_to_the_problem(temp,req_ump);
    }
};
class Solution {
public:
    
    #define ll long long
    
    int widthOfBinaryTree(TreeNode* root) {
       
        queue<pair<TreeNode*, int>> q;

        
        q.push({root, 0});
        
        int max_width = INT_MIN;
        
        while(!q.empty())
        {
            int size = q.size();
            
            int min_idx = q.front().second;
            
            int first_idx, last_idx;
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr_node = q.front().first;
                
                int curr_idx = q.front().second;
                
                curr_idx -= min_idx;
                
                q.pop();
                
                if(i == 0)
                {
                    first_idx = curr_idx;
                }
                
                if(i == size - 1)
                {
                    last_idx = curr_idx;
                }
                
                // push the left child
                
                if(curr_node -> left)
                {
                    q.push({curr_node -> left, (ll) 2 * curr_idx + 1});
                }
                
                if(curr_node -> right)
                {
                    q.push({curr_node -> right, (ll) 2 * curr_idx + 2});
                }
            }

            // update max width

            max_width = max(max_width, last_idx - first_idx + 1);
        }
        return max_width;
    }
};
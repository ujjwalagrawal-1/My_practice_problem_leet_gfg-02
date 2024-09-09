/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> veci(m,vector<int>(n,-1));
        int rs = 0;
        int re = m-1;
        int ce = n-1;
        int cs = 0;
        while(cs <= ce && rs <= re){
            for(int i = cs;i<=ce;i++){
                if(head){
                    veci[rs][i] = head->val;
                    head = head->next;
                }
            }
            rs++;
            for(int i = rs;i<=re;i++){
                if(head){
                    veci[i][ce] = head->val;
                    head = head->next;
                }
            }
            ce--;
            if(rs <= re){
            for(int i = ce;i>=cs;i--){
                if(head){
                    veci[re][i] = head->val;
                    head = head->next;
                }
            }
            re--;
            }
            if(cs <= ce){
            for(int i = re;i>=rs;i--){
                if(head){
                    veci[i][cs] = head->val;
                    head = head->next;
                }
            }
            cs++;
            }
        }
        return veci;
    }
};
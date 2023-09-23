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
ListNode* Find_Function1(ListNode* root,int target){
    if(target == 1){
        return root;
    }
    ListNode* send =  NULL;
    if(root->next){
        target -= 1;
    send = Find_Function1(root->next,target);
    }
    return send;
}
ListNode* Find_Function2(ListNode* root,int target,vector<int>& so){
    if(target == 1){
        so.push_back(root->val);
        return root;
    }
    ListNode* send =  NULL;
    if(root->next){
    so.push_back(root->val);
    target -= 1;
    send = Find_Function2(root->next,target,so);
    }
    return send;
}
void main_fun(int &i,vector<int>& so,ListNode* &root){
    if(i+1 == so.size()){
        root->val = so[i];
        return;
    }
    root->val = so[i];
    i += 1;
    main_fun(i,so,root->next);
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL || head == NULL){
            return head;
        }
        if(left == right){
            return head;
        }
        ListNode* root = head;
        ListNode* find1 = Find_Function1(root,left);
        cout<<find1->val<<endl;
        vector<int> vec;
        right = right - left + 1;
        ListNode* find2 = Find_Function2(find1,right,vec);
        cout<<find2->val<<endl;
        cout<<vec.size()<<endl;
        reverse(vec.begin(),vec.end());
        int i = 0;
        main_fun(i,vec,find1);
        return head;
    }
};
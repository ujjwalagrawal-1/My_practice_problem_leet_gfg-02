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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr1 = list1;
        
        ListNode* ptr3 = list2;
        a--,b++;
        int y = b-a;
        while(a--){
            ptr1 = ptr1->next;
        }
        ListNode* ptr2 = ptr1;
        while(y--){
            ptr2 = ptr2->next;
        }
        while(ptr3->next != NULL){
            ptr3 = ptr3->next;
        }
        ptr1->next = list2;
        ptr3->next = ptr2;
        return list1;
    }
};
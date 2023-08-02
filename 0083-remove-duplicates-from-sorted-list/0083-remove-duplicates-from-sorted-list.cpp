/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteDuplicates(ListNode *head)
        {
            if (head == NULL)
            {
                return NULL;
            }
            if (head->next == NULL)
            {
                return head;
            }
            ListNode *temp = head->next;
            ListNode *prev = head;
           	// if (temp->val == prev->val)
           	// {
           	//     head->next = NULL;
           	//     delete temp;
           	//     return head;
           	// }

            while (temp != NULL)
            {
                if (temp->val == prev->val)
                {
                    ListNode *ptr = temp;
                    temp = temp->next;
                    prev->next = temp;
                    delete ptr;
                }
                else
                {
                    temp = temp->next;
                    prev = prev->next;
                }
            }
            return head;
        }
};
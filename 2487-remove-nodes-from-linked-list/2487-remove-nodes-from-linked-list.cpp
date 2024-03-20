typedef ListNode Node;
class Solution {
public:
Node* solve(stack<int> &st){
    if(st.size() == 1){
        Node* newnode = new Node(st.top());
        return newnode;
    }
    int a = st.top();
    st.pop();
    Node* y = new Node(a);
    y->next = solve(st);
    return y;
}
Node* re(Node* temp){
    Node* prev = NULL;
    Node* curr = temp;
    Node* fut = curr;
    while(curr != NULL){
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }

    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        Node* x = head;
        stack<int> st;
        while(x != NULL){
            while(!st.empty() && st.top() < x->val){
                st.pop();
            }
            st.push(x->val);
            x = x->next;
        }
        Node* q = solve(st);

        q = re(q);
        return q;
    }
};
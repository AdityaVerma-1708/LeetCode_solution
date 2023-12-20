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

    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* smallhead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return smallhead;
    }

    ListNode* reverseList(ListNode* head) {

    //appraoch 1: using new list and stack

        // if (head == nullptr || head->next == nullptr) {
        //     return head;
        // }

        // stack<int> stack;
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     stack.push(temp->val);
        //     temp = temp->next;
        // }

        // //pushing first val to new linkedlist
        // ListNode* head2 = new ListNode(stack.top());
        // temp = head2;   
        // stack.pop();
        // while(!stack.empty()){
        //     ListNode* node = new ListNode(stack.top());
        //     stack.pop();
        //     temp->next = node;
        //     temp = temp->next;
            
        // }
        // temp->next = nullptr;
        // return head2;

    //---------------------------------------------------------------
    //approach 2: stack with original list 
      
        // stack<int> stack;
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     stack.push(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(!stack.empty()){
        //     temp->val = stack.top();
        //     stack.pop();
        //     temp = temp->next;
        // }
        // return head;

    //------------------------------------------------------------------
    //approach 3: iterative, with changing pointer of node not data  

        // ListNode *prev,*curr;
        // prev = nullptr;
        // curr = head;
        // while(curr != nullptr){
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        // }
        // return prev;

    //--------------------------------------------------------------------
    //appraoch 4: recurrsive, with changing the pointers if node
        return reverse(head);
    }   
};
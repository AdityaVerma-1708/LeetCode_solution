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
    void reorderList(ListNode* head) {
    //approach 1: changing the data 
        // deque<int> dq;
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     dq.push_back(temp->val);
        //     temp = temp->next;
        // }
        // int flag = 0;
        // temp = head;
        // while(!dq.empty() && temp != nullptr){
        //     if(flag == 0){
        //         temp->val = dq.front();
        //         dq.pop_front();
        //         flag = 1;
        //     }
        //     else if(flag == 1){
        //         temp->val = dq.back();
        //         dq.pop_back();
        //         flag = 0;
        //     }
        //     temp = temp->next;
        // }

        //but we should do it without modifying the values


    //appproach 2: very good method
    //three steps 
        //-->find middle and divide the linkedlist
        //-->reverse the second linkedlist 
        //-->merge the linkedlist acoording


        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow is middle
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        ListNode* head1 = head;

        //reverse the second linkedlist
        stack<int> stack;
        ListNode* temp = head2;
        while(temp != nullptr){
            stack.push(temp->val);
            temp = temp->next;
        }
        temp = head2;
        while(!stack.empty()){
            temp->val = stack.top();
            stack.pop();
            temp = temp->next;
        }

        while(head2 != nullptr){
            ListNode* temp1 = head1->next;
            ListNode* temp2 = head2->next;

            head1->next = head2;
            head2->next = temp1;

            head1 = temp1;
            head2 = temp2;
        }
    }
};
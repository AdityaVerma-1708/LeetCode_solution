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
    ListNode* deleteMiddle(ListNode* head) {
    //approach 1:
        // ListNode* temp = head;
        // int count = 1;

        // while(temp->next != nullptr){
        //     count++;
        //     temp = temp->next;
        // }


        // temp = head;
        // ListNode* prev = head;
        // for(int i = 1;i<count/2 + 1;i++){
        //     prev = temp; 
        //     temp = temp->next;
        // }

        // if(temp == nullptr){
        //     prev->next = nullptr;
        // }
        // else if(temp == head && prev == head){
        //     head = NULL;
        // }
        // else{
        //     prev->next = temp->next;
        // }

        // return head; 

    //appraoch 2:
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }


        //slow is at middle
        prev->next = slow->next;
        delete(slow);

        return head;

    }
};
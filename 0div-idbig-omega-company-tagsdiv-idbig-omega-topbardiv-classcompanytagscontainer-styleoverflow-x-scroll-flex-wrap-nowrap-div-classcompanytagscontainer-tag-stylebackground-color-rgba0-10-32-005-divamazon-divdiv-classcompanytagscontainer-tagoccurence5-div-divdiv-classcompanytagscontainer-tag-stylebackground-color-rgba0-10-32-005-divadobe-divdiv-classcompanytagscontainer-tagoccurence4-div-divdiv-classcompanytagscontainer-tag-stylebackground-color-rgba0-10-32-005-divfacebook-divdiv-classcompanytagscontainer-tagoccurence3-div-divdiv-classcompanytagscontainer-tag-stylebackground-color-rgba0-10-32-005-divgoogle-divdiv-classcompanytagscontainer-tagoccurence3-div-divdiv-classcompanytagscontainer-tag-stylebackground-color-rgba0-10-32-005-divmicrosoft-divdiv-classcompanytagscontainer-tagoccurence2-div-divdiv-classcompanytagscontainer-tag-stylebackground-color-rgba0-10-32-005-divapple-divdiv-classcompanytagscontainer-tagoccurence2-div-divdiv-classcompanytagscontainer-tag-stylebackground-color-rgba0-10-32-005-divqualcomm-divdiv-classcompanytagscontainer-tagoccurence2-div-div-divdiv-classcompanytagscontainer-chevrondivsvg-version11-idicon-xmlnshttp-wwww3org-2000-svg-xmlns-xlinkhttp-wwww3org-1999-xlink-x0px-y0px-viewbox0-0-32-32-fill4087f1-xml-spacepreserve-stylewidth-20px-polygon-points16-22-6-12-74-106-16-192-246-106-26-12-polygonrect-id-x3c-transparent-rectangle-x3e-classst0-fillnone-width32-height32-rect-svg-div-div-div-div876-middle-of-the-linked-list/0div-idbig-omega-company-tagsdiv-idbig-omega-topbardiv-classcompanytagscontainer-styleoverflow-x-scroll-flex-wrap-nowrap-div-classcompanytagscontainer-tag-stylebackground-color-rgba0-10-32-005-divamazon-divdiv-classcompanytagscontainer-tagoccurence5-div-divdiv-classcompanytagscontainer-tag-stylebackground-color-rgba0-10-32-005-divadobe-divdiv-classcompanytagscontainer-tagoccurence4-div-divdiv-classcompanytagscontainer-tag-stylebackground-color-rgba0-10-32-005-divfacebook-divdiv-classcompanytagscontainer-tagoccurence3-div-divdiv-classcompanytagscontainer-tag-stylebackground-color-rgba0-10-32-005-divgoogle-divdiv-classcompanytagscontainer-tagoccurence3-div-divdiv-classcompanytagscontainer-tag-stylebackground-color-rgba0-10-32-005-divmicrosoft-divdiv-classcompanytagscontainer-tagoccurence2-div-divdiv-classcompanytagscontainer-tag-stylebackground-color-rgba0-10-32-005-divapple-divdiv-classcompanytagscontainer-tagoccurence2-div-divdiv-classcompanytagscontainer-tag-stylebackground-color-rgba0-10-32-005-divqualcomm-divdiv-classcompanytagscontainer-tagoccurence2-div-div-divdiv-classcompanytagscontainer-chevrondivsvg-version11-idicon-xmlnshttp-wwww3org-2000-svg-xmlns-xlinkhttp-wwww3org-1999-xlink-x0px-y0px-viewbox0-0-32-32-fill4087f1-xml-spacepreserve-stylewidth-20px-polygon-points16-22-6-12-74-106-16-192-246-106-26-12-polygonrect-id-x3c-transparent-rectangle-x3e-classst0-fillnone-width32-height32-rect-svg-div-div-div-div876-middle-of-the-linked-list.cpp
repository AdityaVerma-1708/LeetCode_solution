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
    ListNode* middleNode(ListNode* head) {
    //approach 1:
        // int size = 1;
        // ListNode *temp = head;
        // while(temp->next != nullptr){
        //     size++;
        //     temp = temp->next;
        // }
        // temp = head;
        // if(size%2==0){
        //     for(int i=1;i<(size/2 + 1);i++){
        //         temp = temp->next;
        //     }
        //     head = temp;
        // }
        // else{
        //     for(int i=1;i<=size/2;i++){
        //         temp = temp->next;
        //     }
        //     head = temp;
        // }
        // return head;

    //appraoch 2:
        if(head == nullptr || head->next == nullptr){
            return head;
        }    
        else if(head->next->next == nullptr){
            return head->next;
        }
        else{
            ListNode* slow = head;
            ListNode* fast = head->next;

            while(fast != nullptr ){
                fast = fast->next;
                if(fast != nullptr){
                    fast = fast->next;
                }
                slow = slow->next;
            }
            return slow;
        }
    }
};
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
    ListNode* swapPairs(ListNode* head) {
    //appraoch 1: changing the data 
        // if(head == nullptr){
        //     return head;
        // }
        // else if (head->next == nullptr){
        //     return head;
        // }
        // else if(head->next->next == nullptr){
        //     swap(head->val,head->next->val);
        //     return head;
        // }
        // else{
        //     ListNode* temp = head;
        //     while(temp->next != nullptr){
        //         swap(temp->val,temp->next->val);
        //         temp = temp->next;
        //         if(temp->next == nullptr){
        //             break;
        //         }
        //         temp = temp->next;
        //     }
        //     return head;   
        // }

    //appraoch 2: changing the nodes iterative approach 
        // if(head == nullptr){
        //     return head;
        // }
        // else if (head->next == nullptr){
        //     return head;
        // }

        // ListNode* prev = nullptr;
        // ListNode* curr = head;
        // ListNode* nxt = head->next;

        // head = head->next;

        // while(curr != nullptr){
        //     curr->next = nxt->next;
        //     nxt->next = curr;

        //     if(prev != nullptr){
        //         prev->next = nxt;
        //     }

        //     prev = curr;
        //     curr = curr->next;

        //     if(curr == nullptr || curr->next == nullptr ){
        //         break;
        //     }
        //     nxt = curr->next;
        // }
        // return head;

    //appraoch 3: changing nodes using recurrsion

        if(head == nullptr || head->next == nullptr){
            return head;
        }
        else{
            ListNode* temp = head->next;
            head->next = swapPairs(head->next->next);
            temp->next = head;

            return temp;
        }

    
    }
};
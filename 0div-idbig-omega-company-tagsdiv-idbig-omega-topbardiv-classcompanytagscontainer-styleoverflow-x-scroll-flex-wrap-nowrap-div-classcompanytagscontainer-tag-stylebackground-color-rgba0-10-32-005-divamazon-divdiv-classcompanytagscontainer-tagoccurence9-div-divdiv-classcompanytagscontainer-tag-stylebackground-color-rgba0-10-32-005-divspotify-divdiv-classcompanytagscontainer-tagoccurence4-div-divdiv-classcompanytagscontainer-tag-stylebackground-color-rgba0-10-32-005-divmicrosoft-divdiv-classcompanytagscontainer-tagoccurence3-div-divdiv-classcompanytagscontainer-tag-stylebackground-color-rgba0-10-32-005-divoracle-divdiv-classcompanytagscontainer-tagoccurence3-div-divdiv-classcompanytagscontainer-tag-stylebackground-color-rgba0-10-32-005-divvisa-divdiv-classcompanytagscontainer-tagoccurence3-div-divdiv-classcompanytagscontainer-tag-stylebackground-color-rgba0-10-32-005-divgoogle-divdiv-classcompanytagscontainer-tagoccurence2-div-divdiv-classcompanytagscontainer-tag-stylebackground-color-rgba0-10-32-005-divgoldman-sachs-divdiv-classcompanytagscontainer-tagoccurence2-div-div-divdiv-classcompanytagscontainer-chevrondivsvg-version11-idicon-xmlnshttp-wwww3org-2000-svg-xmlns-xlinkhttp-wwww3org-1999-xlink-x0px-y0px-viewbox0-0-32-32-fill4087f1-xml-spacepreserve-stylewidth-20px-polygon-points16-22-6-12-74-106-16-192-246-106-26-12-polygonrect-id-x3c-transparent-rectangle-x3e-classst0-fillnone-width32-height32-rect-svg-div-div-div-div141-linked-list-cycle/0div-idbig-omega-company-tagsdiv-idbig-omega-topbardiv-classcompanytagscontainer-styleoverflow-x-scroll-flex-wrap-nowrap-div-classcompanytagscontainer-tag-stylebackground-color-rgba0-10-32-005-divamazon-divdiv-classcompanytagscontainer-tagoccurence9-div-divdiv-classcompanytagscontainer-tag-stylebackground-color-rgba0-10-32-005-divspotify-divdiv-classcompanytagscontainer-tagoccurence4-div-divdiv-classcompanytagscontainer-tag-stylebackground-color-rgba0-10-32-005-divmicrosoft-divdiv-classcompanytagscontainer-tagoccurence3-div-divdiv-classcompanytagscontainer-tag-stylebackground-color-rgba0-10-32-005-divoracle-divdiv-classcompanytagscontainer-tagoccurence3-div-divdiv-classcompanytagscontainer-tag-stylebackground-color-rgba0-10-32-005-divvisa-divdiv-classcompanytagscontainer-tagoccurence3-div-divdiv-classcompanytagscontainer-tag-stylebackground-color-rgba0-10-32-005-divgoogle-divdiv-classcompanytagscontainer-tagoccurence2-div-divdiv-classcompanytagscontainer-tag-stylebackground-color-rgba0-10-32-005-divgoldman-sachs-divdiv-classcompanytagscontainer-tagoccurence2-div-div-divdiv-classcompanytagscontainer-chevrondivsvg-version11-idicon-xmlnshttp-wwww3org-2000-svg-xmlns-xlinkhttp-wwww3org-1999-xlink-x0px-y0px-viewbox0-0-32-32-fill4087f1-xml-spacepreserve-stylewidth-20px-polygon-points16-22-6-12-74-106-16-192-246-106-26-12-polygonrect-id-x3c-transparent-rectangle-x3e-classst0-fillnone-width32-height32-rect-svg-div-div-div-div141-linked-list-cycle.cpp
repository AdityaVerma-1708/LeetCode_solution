/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    //appraoch 1: using map 
        // if(head == nullptr){
        //     return false;
        // }
        // else if(head->next == nullptr){
        //     return false;
        // }
        // else if(head->next == head){
        //     return true;
        // }
        // else {
        //     map<ListNode*,bool> map;
        //     ListNode* temp = head;
        //     while(temp != nullptr){
        //         if(map[temp] == false){
        //             map[temp] = true;
        //             temp = temp->next;
        //         }
        //         else{
        //             return true;
        //         }
        //     }
        //     return false;
        // }

        //-->SC ~ O(n) and TC ~ O(n)
        //space can be optimised


    //approach 2: flyod's cycle detection algorithm (slow and fast pointer)
    
        if(head == nullptr){
            return false;
        }
        else if (head->next == nullptr){
            return false;
        }
        else if (head->next == head){
            return true;
        }
        else{
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;

                if(fast == slow){
                    return true;
                }
            }
            return false;
        }

    }
};
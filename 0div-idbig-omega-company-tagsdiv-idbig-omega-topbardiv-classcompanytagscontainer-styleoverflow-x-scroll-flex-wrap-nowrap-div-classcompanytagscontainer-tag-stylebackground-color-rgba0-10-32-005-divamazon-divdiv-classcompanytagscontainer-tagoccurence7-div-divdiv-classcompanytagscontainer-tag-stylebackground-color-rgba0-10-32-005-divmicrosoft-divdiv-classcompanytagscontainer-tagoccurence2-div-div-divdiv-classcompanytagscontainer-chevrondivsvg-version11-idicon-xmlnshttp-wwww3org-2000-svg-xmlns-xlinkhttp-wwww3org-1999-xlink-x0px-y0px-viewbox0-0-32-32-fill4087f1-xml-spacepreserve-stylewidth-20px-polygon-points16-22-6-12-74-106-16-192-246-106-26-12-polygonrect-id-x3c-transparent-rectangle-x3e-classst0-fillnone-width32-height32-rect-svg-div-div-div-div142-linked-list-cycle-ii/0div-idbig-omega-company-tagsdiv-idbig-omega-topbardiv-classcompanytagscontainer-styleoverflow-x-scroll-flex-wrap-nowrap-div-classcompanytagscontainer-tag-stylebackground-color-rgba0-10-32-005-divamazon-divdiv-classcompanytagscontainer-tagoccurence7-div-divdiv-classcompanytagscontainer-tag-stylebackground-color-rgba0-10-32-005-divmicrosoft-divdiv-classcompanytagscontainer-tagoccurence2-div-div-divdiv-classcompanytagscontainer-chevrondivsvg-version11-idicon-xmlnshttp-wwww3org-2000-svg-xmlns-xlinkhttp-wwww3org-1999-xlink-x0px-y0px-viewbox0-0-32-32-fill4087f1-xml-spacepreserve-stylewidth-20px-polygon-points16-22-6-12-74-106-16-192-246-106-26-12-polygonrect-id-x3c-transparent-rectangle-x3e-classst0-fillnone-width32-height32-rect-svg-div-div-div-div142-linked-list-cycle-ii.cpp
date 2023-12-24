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
    ListNode *detectCycle(ListNode *head) {
    //approch 1 : using map 
        // if(head == nullptr){
        //     return nullptr;
        // }    
        // else if(head->next == nullptr){
        //     return nullptr;
        // }
        // else if(head->next == head){
        //     return head;
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
        //             return temp;
        //         }
        //     }
        //     return nullptr;
        // }
        
        //-->SC ~ O(n) and TC ~ O(n)
        //space can be optimised

    //appraoch 2: by modifying the flyod's cycle detection algo
        if(head == nullptr){
            return nullptr;
        }
        else if (head->next == nullptr){
            return nullptr;
        }
        else if (head->next == head){
            return head;
        }
        else{
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;

                if(fast == slow){ //cycle exists
                    slow = head;
                    while(slow != fast){
                        slow = slow->next;
                        fast = fast->next;
                    }
                    
                    return slow;
                }
            }
            return nullptr;
        }
        //SC ~ O(1) and TC ~ O(n2);
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
    //appraoch 1: brute force
        if(head == nullptr){
            return head;
        }
        else if (head->next == nullptr){
            return head;
        }
        else{
            ListNode* temp = head;
            while(temp->next != nullptr){
                if(temp->val == temp->next->val){
                    ListNode* temp2 = temp->next;
                    temp->next = temp2->next;
                }
                else{
                    temp = temp->next;
                }

            }
            return head;
        }
    }
};
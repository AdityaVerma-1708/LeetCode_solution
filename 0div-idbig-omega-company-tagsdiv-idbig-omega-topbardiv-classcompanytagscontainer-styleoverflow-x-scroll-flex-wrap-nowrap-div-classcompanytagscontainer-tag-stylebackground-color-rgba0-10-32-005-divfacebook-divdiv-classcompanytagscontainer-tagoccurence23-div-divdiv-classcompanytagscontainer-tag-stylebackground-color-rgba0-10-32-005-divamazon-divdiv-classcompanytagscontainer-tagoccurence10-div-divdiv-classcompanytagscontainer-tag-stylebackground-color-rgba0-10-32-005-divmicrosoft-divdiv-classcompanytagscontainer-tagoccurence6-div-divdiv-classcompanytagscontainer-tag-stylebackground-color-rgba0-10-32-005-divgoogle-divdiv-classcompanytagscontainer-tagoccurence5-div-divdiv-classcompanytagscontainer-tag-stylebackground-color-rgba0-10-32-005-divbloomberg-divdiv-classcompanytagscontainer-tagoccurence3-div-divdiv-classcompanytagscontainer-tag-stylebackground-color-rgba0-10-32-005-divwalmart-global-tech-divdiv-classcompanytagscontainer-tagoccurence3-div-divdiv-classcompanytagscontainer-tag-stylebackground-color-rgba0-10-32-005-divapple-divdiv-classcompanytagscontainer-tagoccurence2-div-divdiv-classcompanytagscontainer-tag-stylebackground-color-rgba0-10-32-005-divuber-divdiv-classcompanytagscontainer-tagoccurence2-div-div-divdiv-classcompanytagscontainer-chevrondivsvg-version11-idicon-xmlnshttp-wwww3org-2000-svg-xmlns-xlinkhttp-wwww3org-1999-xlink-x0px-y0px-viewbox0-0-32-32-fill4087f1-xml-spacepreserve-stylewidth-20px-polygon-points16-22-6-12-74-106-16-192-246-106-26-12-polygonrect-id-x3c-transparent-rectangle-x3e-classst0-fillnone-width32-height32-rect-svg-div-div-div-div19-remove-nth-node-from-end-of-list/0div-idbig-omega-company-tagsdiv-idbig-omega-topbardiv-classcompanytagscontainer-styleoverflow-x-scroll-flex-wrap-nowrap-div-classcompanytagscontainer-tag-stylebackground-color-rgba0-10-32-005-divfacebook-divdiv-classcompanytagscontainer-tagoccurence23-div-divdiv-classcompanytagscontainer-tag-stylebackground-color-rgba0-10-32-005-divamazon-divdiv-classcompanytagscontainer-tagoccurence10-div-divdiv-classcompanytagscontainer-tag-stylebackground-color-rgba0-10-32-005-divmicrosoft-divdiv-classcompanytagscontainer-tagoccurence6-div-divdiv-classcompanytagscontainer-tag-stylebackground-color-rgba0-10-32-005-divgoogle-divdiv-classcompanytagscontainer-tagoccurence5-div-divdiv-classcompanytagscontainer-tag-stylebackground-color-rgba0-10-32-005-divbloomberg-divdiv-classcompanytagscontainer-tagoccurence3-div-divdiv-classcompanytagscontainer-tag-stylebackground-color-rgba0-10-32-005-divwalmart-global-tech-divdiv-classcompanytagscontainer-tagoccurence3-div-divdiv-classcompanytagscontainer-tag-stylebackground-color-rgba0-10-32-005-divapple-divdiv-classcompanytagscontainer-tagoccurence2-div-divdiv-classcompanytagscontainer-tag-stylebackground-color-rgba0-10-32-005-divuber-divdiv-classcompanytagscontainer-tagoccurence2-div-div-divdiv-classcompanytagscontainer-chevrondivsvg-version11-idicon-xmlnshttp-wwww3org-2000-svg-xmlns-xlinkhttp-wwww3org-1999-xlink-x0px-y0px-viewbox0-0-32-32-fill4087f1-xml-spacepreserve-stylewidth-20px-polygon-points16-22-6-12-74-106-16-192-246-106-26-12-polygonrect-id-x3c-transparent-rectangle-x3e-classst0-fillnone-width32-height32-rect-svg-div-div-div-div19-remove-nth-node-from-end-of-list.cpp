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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //approach 1: my approach TC ~ O(n) SC ~ O(1)
        if(head == nullptr){
            return head;
        }
        else if (head->next == nullptr && n == 1){
            head = nullptr;
            return head;
        }
        else{
            ListNode* back = nullptr;
            ListNode* temp = head;
            ListNode* forth = head;
            int count = 1;
            while(count < n){
                forth = forth->next;
                count++;
            }

            while(forth->next != nullptr){
                forth = forth->next;
                back = temp;
                temp = temp->next;
            }
            if(temp == head){
                head = head->next;
            }
            else{
                back->next = temp->next;
            }
            return head;
        }
    }
};
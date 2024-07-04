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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *head1 = nullptr;
        ListNode *second = head->next;
        ListNode *middle = head;
        

        while(second!= nullptr){
            int sum = 0;
            while(second->val != 0){
                sum = sum + second->val;
                second = second->next;
            }

            second->val = sum;
            // middle = second;
            if(head1 == nullptr){
                head1 = second;
                middle = head1;
            }
            else{
                middle->next = second;
                middle = second;
            }

            second = second->next;
            
            
        }
        return head1;
    }
};
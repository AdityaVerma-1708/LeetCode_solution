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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //here just we need to reverse the number then add it 
    //approach 1: recurrsion
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;

        l1 = reverse(l1);
        l2 = reverse(l2);
        
        while(l1 != nullptr && l2 != nullptr){
            int sum = carry + l1->val + l2->val;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = node;

            carry = sum/10;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr){
            int sum = carry + l1->val;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = node;

            carry = sum/10;

            l1 = l1->next;
        }

        while(l2 != nullptr){
            int sum = carry + l2->val;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = node;

            carry = sum/10;

            l2 = l2->next;
        }

        while(carry != 0){
            ListNode* node = new ListNode(carry%10);
            temp->next = node;
            temp = node;

            carry = carry/10;
        }
        
        dummy = reverse(dummy->next);
        return dummy;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
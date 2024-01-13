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
    bool isPalindrome(ListNode* head) {
    //there can be so many different aproaches to solve this question
    //approach 1: using extra space
        // if(head->next == nullptr){
        //     return true;
        // }
        // else if(head->next->next == nullptr){
        //     if(head->val == head->next->val){
        //         return true;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // else{
        //     vector<int> v;
        //     ListNode* temp = head;
        //     while(temp != nullptr){
        //         v.push_back(temp->val);
        //         temp = temp->next;
        //     }
        //     int i = 0;
        //     int j = v.size()-1;

        //     while(i<=j){
        //         if(v[i] != v[j]){
        //             return false;
        //         }
        //         i++;
        //         j--;
        //     }
        //     return true;
        // }

    //appraoch 2: not using the extra space

        if(head->next == nullptr){
            return true;
        }
        else if(head->next->next == nullptr){
            if(head->val == head->next->val){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
                fast = fast->next->next;
                slow = slow->next;
            } 

            ListNode* temp = slow->next;
            slow->next = reverse(temp);

            ListNode* head2 = slow->next;
            ListNode* head1 = head;

            while(head1 != slow->next && head2 != nullptr){
                if(head1->val != head2->val){
                    return false;
                }
                head1 = head1->next;
                head2 = head2->next;

            }
            return true;
        }
    }

    ListNode* reverse(ListNode* head){
        ListNode* next = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

};
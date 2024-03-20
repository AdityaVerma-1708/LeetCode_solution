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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    //appraoch 1:
        int count1 = 0;
        ListNode* curr1 = list1;
        ListNode* curr2 = nullptr;
        ListNode* prev = nullptr;

        while(count1 != a){
            prev = curr1;
            curr1 = curr1->next;
            count1++;
        }

        prev->next = list2;
        curr2 = prev->next;

        while(curr2->next != nullptr){
            curr2 = curr2->next;
        }

        while(count1 != b){
            curr1 = curr1->next;
            count1++;
        }

        curr2->next = curr1->next;
        curr1->next = nullptr;

        return list1;
    }
};
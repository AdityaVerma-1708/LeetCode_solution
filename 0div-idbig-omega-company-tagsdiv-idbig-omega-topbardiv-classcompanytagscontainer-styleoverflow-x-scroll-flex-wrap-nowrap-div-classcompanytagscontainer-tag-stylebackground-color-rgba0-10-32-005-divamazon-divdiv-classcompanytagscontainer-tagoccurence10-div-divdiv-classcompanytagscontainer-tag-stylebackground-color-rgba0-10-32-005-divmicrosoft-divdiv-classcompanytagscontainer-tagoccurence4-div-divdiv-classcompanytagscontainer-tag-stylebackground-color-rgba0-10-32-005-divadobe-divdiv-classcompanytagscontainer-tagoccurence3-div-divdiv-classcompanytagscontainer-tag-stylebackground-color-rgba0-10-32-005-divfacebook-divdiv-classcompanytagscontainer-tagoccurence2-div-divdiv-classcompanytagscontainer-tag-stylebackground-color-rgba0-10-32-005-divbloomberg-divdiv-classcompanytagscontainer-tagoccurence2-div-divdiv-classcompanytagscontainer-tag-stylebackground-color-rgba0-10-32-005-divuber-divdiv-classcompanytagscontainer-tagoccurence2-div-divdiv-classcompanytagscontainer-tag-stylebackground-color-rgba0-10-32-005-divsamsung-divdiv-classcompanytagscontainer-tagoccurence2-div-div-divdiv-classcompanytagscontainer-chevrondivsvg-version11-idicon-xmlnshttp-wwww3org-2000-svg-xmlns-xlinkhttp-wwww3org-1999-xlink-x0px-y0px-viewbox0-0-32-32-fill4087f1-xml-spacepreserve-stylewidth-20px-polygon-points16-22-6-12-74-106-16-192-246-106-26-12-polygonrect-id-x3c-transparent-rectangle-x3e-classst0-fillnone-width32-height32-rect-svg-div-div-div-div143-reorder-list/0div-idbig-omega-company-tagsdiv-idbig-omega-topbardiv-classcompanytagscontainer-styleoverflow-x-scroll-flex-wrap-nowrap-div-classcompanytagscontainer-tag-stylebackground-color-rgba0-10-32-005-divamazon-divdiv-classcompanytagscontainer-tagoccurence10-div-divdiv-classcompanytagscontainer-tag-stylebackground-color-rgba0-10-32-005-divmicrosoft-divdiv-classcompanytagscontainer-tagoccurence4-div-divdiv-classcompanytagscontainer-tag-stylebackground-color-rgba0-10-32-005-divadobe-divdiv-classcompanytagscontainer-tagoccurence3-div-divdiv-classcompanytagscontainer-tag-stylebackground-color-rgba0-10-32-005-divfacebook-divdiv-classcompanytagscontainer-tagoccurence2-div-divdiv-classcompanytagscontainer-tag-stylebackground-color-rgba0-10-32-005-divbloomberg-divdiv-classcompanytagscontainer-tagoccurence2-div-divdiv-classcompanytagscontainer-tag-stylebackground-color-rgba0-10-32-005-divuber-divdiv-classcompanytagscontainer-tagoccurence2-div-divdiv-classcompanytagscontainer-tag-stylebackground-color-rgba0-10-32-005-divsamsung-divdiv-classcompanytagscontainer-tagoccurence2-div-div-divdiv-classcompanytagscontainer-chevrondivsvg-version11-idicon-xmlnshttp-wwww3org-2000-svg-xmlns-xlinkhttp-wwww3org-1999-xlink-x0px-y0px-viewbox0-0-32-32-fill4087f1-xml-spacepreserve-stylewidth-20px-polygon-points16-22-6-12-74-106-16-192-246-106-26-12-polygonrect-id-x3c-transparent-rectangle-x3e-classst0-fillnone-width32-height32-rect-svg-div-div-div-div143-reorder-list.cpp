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
    void reorderList(ListNode* head) {
    //approach 1: changing the data 
        deque<int> dq;
        ListNode* temp = head;
        while(temp != nullptr){
            dq.push_back(temp->val);
            temp = temp->next;
        }
        int flag = 0;
        temp = head;
        while(!dq.empty() && temp != nullptr){
            if(flag == 0){
                temp->val = dq.front();
                dq.pop_front();
                flag = 1;
            }
            else if(flag == 1){
                temp->val = dq.back();
                dq.pop_back();
                flag = 0;
            }
            temp = temp->next;
        }

        //but we should do it without modifying the values
    }
};
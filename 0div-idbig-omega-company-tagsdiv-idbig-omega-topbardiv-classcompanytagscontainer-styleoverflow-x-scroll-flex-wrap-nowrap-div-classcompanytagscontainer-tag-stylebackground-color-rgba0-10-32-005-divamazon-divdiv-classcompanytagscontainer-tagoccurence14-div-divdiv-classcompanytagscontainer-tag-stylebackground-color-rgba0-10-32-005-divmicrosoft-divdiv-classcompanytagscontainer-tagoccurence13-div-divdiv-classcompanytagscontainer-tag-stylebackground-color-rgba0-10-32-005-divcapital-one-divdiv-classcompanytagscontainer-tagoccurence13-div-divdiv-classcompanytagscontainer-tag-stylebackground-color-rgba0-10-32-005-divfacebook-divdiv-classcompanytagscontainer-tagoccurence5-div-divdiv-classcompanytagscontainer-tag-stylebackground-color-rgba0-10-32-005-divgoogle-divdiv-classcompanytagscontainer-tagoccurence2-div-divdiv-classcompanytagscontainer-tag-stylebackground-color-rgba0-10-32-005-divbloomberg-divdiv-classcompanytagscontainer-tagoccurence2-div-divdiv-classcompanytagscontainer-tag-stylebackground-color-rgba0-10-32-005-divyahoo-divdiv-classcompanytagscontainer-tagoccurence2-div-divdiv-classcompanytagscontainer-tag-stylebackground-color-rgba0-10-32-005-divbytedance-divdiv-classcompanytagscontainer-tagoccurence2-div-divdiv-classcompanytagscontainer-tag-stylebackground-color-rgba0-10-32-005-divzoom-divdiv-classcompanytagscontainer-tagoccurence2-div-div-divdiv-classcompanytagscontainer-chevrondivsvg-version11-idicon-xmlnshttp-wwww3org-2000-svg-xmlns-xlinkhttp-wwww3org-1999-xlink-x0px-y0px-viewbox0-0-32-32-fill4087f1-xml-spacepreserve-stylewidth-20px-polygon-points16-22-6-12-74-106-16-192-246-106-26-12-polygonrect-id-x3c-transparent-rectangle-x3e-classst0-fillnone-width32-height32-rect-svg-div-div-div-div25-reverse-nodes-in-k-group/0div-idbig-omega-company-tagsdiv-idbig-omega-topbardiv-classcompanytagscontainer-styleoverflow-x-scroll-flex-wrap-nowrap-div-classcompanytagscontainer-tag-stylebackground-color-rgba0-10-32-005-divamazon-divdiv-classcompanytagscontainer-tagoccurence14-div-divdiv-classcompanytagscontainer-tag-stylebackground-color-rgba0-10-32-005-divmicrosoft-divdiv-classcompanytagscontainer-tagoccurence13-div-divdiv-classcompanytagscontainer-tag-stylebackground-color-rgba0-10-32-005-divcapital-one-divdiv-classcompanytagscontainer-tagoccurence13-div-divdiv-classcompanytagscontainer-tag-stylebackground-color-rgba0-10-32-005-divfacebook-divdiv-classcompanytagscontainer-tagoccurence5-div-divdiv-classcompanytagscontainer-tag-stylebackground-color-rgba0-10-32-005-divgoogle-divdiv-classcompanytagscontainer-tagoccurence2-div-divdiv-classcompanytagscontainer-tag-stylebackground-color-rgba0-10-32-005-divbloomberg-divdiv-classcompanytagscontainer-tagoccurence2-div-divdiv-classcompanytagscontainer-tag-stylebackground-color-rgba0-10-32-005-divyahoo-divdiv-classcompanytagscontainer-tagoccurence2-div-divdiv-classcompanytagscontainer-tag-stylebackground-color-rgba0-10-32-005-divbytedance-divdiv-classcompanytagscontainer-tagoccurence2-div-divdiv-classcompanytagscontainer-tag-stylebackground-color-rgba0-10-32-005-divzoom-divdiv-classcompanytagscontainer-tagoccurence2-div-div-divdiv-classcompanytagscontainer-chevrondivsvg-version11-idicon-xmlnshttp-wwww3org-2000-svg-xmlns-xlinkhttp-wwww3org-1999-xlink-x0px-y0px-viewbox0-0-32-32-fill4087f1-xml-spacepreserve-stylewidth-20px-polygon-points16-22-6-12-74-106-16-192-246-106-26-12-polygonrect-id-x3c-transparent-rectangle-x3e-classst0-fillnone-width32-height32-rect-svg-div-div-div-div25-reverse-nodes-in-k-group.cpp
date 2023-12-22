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
    ListNode* reverseKGroup(ListNode* head, int k) {
    //appraoch 1: using stack(my approach) ~O(n2)
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     int a = 1;
        //     stack<int> stack;
        //     ListNode* temp2 = temp;
        //     int flag = 0;
        //     while(a <= k){
        //         stack.push(temp2->val);
        //         if(temp2->next == nullptr){
        //             flag = 1;
        //             break;
        //         }
        //         temp2 = temp2->next;
        //         a++;
        //     }
        //     if(flag == 1 && stack.size() != k){
        //         break;
        //     }
        //     temp2 = temp;
        //     while(!stack.empty()){
        //         temp2->val = stack.top();
        //         stack.pop();
        //         temp2 = temp2->next; 
        //     }
        //     temp = temp2;
        // }
        // return head;  

    //appraoch 2: recurrsion 

        //base case
        if(head == nullptr){
            return nullptr;
        }

        //step 1: reverse first k nodes
        ListNode* next = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int count = 0;

        while(curr != nullptr && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(count < k){   //if count < k then we have to reverse back that part of linkedlist
            ListNode* temp = nullptr;
            while (prev != nullptr) {
                temp = prev->next;
                prev->next = curr;
                curr = prev;
                prev = temp;
            }
            return curr;
        }

        //step 2: recursion dekh lega 
        if(next != nullptr){
            head->next = reverseKGroup(next,k);
        }
        
        //step 3: return head of reversed linkedlist
        return prev;

    }
};
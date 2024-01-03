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
    //appraoch 1: using dequeue and modiying the ll
        // if(head == nullptr){
        //     return head;
        // }
        // else if(head->next == nullptr){
        //     return head;
        // }
        // else{
        //     deque<int> dq;
        //     ListNode* temp = head;
        //     int flag = 0;
        //     while(temp != nullptr){
        //         if(!dq.empty() && dq.back() == temp->val){
        //             flag = 1;
        //             temp = temp->next;
        //         }
        //         else{
        //             if(flag == 1){
        //                 dq.pop_back();
        //                 flag = 0;
        //             }
        //             dq.push_back(temp->val);
        //             temp = temp->next;
        //         }
        //     }
            
        //     if(flag == 1){
        //         dq.pop_back();
        //     }

        //     if(dq.empty()){
        //         head = nullptr;
        //         return head;
        //     }

        //     temp = head;
        //     while(!dq.empty()){
        //         temp->val = dq.front();
        //         dq.pop_front();

        //         if(dq.size() == 0){
        //             temp->next = nullptr;
        //             break;
        //         }
        //         temp = temp->next;
        //     }

        //     return head;
        // }

    //appraoch 2: reducing the space complexity SC ~ O(1) tc ~ O(n)
        if(head == nullptr){
            return head;
        }
        else if(head->next == nullptr){
            return head;
        }
        // else if (head->next->next == nullptr){
        //     if(head->val == head->next->val){
        //         head = nullptr;
        //     }
        //     return head;
        // }
        else{
            ListNode* temp = head;
            ListNode* back = nullptr;
            ListNode* forth = head->next;
            int flag = 0;
            while(forth != nullptr){
                if(temp->val == forth->val && forth->next != nullptr){
                    flag = 1;
                    forth = forth->next;
                }
                else{
                    if(flag == 1){
                        if(back == nullptr && forth->val == temp->val){
                            //case where forth is at last and its val equal to temp val
                            //and back is null
                            head = forth->next;
                        }
                        else if (back == nullptr && forth->val != temp->val){
                            //normal case with back equal null
                            head = forth;
                            temp = forth;
                            forth = forth->next;
                        }
                        else if(back != nullptr && forth->val == temp->val){
                            //case where forth is at last and its val equal to temp val
                            //back is not null
                            back->next = forth->next;
                            temp = forth;
                            forth = forth->next;
                        }
                        else{
                            //normal case with back equal null
                            back->next = forth;
                            temp = forth;
                            forth = forth->next;
                        }
                        flag = 0;
                    }
                    else{
                        if(back == nullptr && forth->val != temp->val){
                            back = head;
                            temp = temp->next;
                            forth = forth->next;
                        }
                        else if(back != nullptr && forth->val == temp->val){
                            back->next = forth->next;
                            temp = temp->next;
                            forth = forth->next;
                        }
                        else if(back == nullptr && forth->val == temp->val){
                            head = nullptr;
                            temp = temp->next;
                            forth = forth->next;
                        }
                        else {
                            back = back->next;
                            temp = temp->next;
                            forth = forth->next;
                        }
                    }
                }
            }
            return head;
        }
             
    }
};
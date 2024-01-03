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
        // if(head == nullptr){
        //     return head;
        // }
        // else if (head->next == nullptr){
        //     return head;
        // }
        // else{
        //     ListNode* temp = head;
        //     while(temp->next != nullptr){
        //         if(temp->val == temp->next->val){
        //             ListNode* temp2 = temp->next;
        //             temp->next = temp2->next;
        //             delete(temp2);
        //         }
        //         else{
        //             temp = temp->next;
        //         }

        //     }
        //     return head;
        // }

        ///we can do this q by using the set which will increase the space complexity 
    
    //approach 2: using sets 
    //this can be done by two differnt approach , creating new ll (easy) modifying the old ll(moderate) we are doing the second one 
        if(head == nullptr){
            return head;
        }
        else if (head->next == nullptr){
            return head;
        }
        else{
            set<int>set;
            ListNode* temp = head;
            while(temp != nullptr){
                set.insert(temp->val);
                temp = temp->next;
            }

            temp = head;
            for(auto it = set.begin();it != set.end();it++){
                temp->val = *it;
                auto itr = it;
                if(++itr == set.end()){
                    temp->next = nullptr;
                    break;
                }
                temp = temp->next;
            }
            return head;
        }  
    }
};
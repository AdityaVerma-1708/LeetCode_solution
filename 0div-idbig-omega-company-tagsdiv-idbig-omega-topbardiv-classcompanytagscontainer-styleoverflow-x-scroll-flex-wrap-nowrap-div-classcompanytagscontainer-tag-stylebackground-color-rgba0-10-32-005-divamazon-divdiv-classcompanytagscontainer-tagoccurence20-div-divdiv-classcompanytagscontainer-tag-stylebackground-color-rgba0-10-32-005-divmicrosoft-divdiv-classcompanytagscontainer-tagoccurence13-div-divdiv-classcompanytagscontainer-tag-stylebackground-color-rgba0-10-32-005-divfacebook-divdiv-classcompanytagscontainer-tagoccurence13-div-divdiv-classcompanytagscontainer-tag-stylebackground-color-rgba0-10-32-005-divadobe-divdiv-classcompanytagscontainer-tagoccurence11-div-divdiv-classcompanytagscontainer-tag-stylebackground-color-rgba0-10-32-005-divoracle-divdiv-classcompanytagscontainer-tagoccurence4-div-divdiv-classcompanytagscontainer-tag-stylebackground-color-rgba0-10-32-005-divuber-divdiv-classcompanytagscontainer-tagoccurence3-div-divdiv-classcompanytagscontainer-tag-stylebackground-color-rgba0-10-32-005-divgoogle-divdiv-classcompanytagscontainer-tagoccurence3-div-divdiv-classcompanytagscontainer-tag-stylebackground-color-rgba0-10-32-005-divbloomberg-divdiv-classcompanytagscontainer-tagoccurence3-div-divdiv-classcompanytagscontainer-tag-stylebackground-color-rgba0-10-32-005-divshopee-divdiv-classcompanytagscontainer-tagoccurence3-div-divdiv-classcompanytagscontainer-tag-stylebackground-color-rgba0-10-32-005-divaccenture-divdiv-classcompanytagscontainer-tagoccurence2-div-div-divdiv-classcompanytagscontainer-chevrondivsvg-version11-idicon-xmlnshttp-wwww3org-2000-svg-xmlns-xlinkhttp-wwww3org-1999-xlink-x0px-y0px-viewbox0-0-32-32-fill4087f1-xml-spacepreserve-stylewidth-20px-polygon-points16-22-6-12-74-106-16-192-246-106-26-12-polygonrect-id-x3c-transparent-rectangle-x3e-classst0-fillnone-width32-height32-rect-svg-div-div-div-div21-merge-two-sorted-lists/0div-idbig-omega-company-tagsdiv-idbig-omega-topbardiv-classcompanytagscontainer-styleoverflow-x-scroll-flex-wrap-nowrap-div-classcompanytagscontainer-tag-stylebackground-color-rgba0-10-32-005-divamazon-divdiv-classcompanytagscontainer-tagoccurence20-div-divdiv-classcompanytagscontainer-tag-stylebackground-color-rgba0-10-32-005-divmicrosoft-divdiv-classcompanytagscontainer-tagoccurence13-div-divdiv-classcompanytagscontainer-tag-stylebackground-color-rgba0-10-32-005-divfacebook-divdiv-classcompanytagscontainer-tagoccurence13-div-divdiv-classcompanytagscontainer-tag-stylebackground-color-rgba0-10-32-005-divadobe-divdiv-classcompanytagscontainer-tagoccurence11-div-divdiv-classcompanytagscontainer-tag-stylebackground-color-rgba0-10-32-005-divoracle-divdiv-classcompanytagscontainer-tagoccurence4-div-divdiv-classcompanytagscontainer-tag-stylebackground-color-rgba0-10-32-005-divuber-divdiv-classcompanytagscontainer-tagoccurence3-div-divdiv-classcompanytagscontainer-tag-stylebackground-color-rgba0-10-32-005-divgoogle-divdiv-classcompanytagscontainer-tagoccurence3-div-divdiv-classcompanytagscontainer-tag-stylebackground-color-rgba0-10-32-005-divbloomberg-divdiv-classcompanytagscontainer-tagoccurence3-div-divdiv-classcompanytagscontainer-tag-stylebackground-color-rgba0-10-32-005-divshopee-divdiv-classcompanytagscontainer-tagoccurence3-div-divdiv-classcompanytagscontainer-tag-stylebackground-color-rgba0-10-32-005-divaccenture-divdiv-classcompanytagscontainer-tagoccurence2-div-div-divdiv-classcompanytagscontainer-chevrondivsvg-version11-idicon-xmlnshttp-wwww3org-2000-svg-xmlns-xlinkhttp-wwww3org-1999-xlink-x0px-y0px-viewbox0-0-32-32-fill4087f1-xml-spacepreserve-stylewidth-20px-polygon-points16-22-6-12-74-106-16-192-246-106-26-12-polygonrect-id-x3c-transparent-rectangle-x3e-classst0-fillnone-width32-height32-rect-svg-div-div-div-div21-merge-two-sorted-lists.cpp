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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //there are so many ways to solve this problem but we will see some good ones

    //appraoch 1: using the new list 
        // ListNode* list3 = new ListNode();
        // ListNode* temp1 = list1;
        // ListNode* temp2 = list2;
        // ListNode* temp3 = list3;

        // while(temp1 != nullptr && temp2 != nullptr){
        //     if(temp1->val > temp2->val){
        //         ListNode* node = new ListNode(temp2->val);
        //         temp3->next = node;
        //         temp3 = node;

        //         temp2 = temp2->next;
        //     }
        //     else if(temp1->val < temp2->val){
        //         ListNode* node = new ListNode(temp1->val);
        //         temp3->next = node;
        //         temp3 = node;

        //         temp1 = temp1->next;
        //     }
        //     else{
        //         ListNode* node = new ListNode(temp1->val);
        //         temp3->next = node;
        //         temp3 = node;

        //         ListNode* node2 = new ListNode(temp2->val);
        //         temp3->next = node2;
        //         temp3 = node2;

        //         temp1 = temp1->next;
        //         temp2 = temp2->next;
        //     }
        // }
        // //putting remaining
        // while(temp1 != nullptr){
        //     ListNode* node = new ListNode(temp1->val);
        //     temp3->next = node;
        //     temp3 = node;
                
        //     temp1 = temp1->next;
        // }
        // while(temp2 != nullptr){
        //     ListNode* node = new ListNode(temp2->val);
        //     temp3->next = node;
        //     temp3 = node;
                
        //     temp2 = temp2->next;
        // }
        // return list3->next;


    //approach 2: not using the new list
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val > temp2->val){
                temp->next = temp2;
                temp = temp->next;

                temp2 = temp2->next;
            }
            else if(temp1->val < temp2->val){
                temp->next = temp1;
                temp = temp->next;

                temp1 = temp1->next;
            }
            else{ //if both equal
                temp->next = temp1;
                temp = temp->next;
                
                temp1 = temp1->next;  //very important if puts afterwards will show TLE

                temp->next = temp2;
                temp = temp->next;

                temp2 = temp2->next;
            }
        }
        //connecting remaining nodes
        if(temp1 != nullptr){
            temp->next = temp1;
        }
        if(temp2 != nullptr){
            temp->next = temp2;
        }
        return dummy->next;
    }
};
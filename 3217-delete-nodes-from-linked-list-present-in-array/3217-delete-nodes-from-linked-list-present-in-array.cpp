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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    //appraoch 1:
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            int data = temp->val;
            bool flag = false;

            for(int i = 0;i<nums.size();i++){
                if(data == nums[i]){
                    flag = true;
                    break;
                }
            }

            if(flag == false){
                prev = temp;
                temp = temp->next;
            }
            else{ //flag == true
                if(prev == nullptr){
                    //means first node only we need to delete
                    temp = temp->next;
                    prev = nullptr;
                    head = temp;
                }
                else{  //between nodes
                    if(temp->next == nullptr){
                        //last node delete
                        prev->next = nullptr;
                        temp = temp->next;
                    }
                    else{
                        prev->next = temp->next;
                        temp = prev;
                    }
                }
            }
        }
        return head;
    }
};
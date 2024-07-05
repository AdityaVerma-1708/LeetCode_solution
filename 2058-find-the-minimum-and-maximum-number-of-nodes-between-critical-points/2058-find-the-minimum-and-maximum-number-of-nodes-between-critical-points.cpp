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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>index;
        if(head->next->next == nullptr){
            return {-1,-1};   
        }
        else{
            ListNode* prev = head;
            ListNode* middle = head->next;
            ListNode* temp = head->next->next;
            int i = 2; //positioned at middle 

            while(temp != nullptr){
                int middleval = middle->val;
                int prevval = prev->val;
                int nextval = temp->val;

                if((middleval > prevval && middleval > nextval) || (middleval < prevval && middleval < nextval)){
                    index.push_back(i);
                }

                prev = middle;
                middle = temp;
                temp = temp->next;
                i++;
            }

            if(index.size() <= 1){
                return {-1,-1};
            }
            else{
                // sort(index.begin(),index.end());
                int maxi = index[index.size()-1] - index[0];
                int mini = INT_MAX;
                for(int i = 1;i<index.size();i++){
                    mini = min(mini,index[i] - index[i-1]);
                }

                return {mini,maxi};
            }
        }
    }
};
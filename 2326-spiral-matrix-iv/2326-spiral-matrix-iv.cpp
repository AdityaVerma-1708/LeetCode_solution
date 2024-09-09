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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int> (n,-1));
        ListNode* temp = head;
        int i = 0;
        int j = 0;
        while(temp != nullptr){

            while(temp != nullptr && j < n && i < m && ans[i][j] == -1){
                ans[i][j] = temp->val;
                temp = temp->next;
                j++;
            }
            j--;
            i++;

            while(temp != nullptr && i < m && j < n && ans[i][j] == -1){
                ans[i][j] = temp->val;
                temp = temp->next;
                i++;
            }
            i--;
            j--;

            while(temp != nullptr && j >= 0 && i < m && ans[i][j] == -1){
                ans[i][j] = temp->val;
                temp = temp->next;
                j--;
            }
            j++;
            i--;

            while(temp != nullptr && i>=0 && j>=0 && ans[i][j] == -1){
                ans[i][j] = temp->val;
                temp = temp->next;
                i--;
            }
            j++;
            i++;
        }
        return ans;
    }
};
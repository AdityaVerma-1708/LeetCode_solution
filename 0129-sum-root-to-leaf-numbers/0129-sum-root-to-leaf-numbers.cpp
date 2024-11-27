/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* node,vector<int>& number,int num){
        if(node->left == nullptr && node->right == nullptr){
            number.push_back(num);
            return;
        }

        int left = num;
        int right = num;

        if(node->left != nullptr){
            left = left*10 + node->left->val;
            solve(node->left,number,left);
        }

        if(node->right != nullptr){
            right = right*10 + node->right->val;
            solve(node->right,number,right);
        }
    }

    int sumNumbers(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        vector<int> number;
        solve(root,number,root->val);

        int ans = 0;
        for(int i = 0;i<number.size();i++){
            ans = ans + number[i];
        }

        return ans;
    }
};
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
//approach 1: recurrsion

    int solve(TreeNode* node,int count){
        if(node->left == nullptr && node->right == nullptr){
            return count;
        }

        int left = INT_MAX;
        int right = INT_MAX;

        if(node->left != nullptr){
            left = solve(node->left,count+1);
        }

        if(node->right != nullptr){
            right = solve(node->right,count+1);
        }
       
        return min(left,right);
    }

    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        return solve(root,1);
    }
};
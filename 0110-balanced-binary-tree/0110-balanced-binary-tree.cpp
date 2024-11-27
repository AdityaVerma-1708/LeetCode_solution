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
//approach 1: brute force
    // int findsize(TreeNode* node,int count){
    //     if(node->left == nullptr && node->right == nullptr){
    //         return count;
    //     }

    //     int left = 0;
    //     int right = 0;

    //     if(node->left != nullptr){
    //         left = findsize(node->left,count+1);
    //     }

    //     if(node->right != nullptr){
    //         right = findsize(node->right,count+1);
    //     }

    //     return max(left,right);
    // }


    // bool isBalanced(TreeNode* root) {
    //     if(root == nullptr){
    //         return true;
    //     }
    //     else if (root->left == nullptr && root->right == nullptr){
    //         return true;
    //     }
    //     else{
    //         int left = 0;
    //         int right = 0;

    //         if(root->left !=  nullptr){
    //             left = findsize(root->left,1);
    //         }

    //         if(root->right != nullptr){
    //             right = findsize(root->right,1);
    //         }

    //         if(abs(left-right) > 1){
    //             return false;
    //         }
    //         else{
    //             if(isBalanced(root->left) && isBalanced(root->right)){
    //                 return true;
    //             }
    //             else{
    //                 return false;
    //             }
    //         }
    //     }
    // }

//approach 2:

    int solve(TreeNode* node, int count){
        if(node->left == nullptr && node->right == nullptr){
            return count;
        }

        int left = count;
        int right = count;

        if(node->left != nullptr){
            left = solve(node->left,count+1);
        }

        if(node->right != nullptr){
            right = solve(node->right,count+1);
        }

        if(left == -1 || right == -1){
            return -1;
        }

        if(abs((left-count) - (right-count)) > 1){
            return -1;
        }

        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        if(solve(root,1) == -1){
            return false;
        }
        else{
            return true;
        }
    }
};
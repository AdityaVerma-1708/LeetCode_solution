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

//approach 1: using recurrsion

    // void inorder(TreeNode* root,vector<int>& ans){
    //     if(root == nullptr){
    //         return;
    //     }

    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);

    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     inorder(root,ans);
    //     return ans;
    // }

//approach 2: using iterative approach 
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>ans;
        stack<TreeNode*> st;
        if(root == nullptr){
            return ans;
        }
        TreeNode* node = root;
        while(true){
            if(node !=  nullptr){
                st.push(node);
                node = node->left;
            }
            else {
                if(st.empty() ){
                    break;
                }
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }    
};
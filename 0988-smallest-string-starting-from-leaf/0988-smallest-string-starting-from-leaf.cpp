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
//approach 1: exploring all strings;  tc ~ O(nlogn) sc ~ O(n2)

    // void solve(TreeNode* node,set<string>& set,string temp){
    //     if(node->left == nullptr && node->right == nullptr){
    //         reverse(temp.begin(),temp.end());
    //         set.insert(temp);
    //         return;
    //     }

    //     if(node->left != nullptr){
    //         string left = temp + char(97 + node->left->val);
    //         solve(node->left,set,left);
    //     }

    //     if(node->right != nullptr){
    //         string right = temp + char(97 + node->right->val);
    //         solve(node->right,set,right);
    //     }
    // }

    // string smallestFromLeaf(TreeNode* root) {
    //     set<string> set;
    //     if(root == nullptr){
    //         return "";
    //     }
        
    //     string temp = "";
    //     temp = temp + char(97 + root->val);

    //     solve(root,set,temp);

    //     return *set.begin();
    // }

//approach 1:

    void solve(TreeNode* node,vector<string>& arr,string temp){
        if(node->left == nullptr && node->right == nullptr){
            arr.push_back(temp);
            return;
        }

        if(node->left != nullptr){
            string left = char(97 + node->left->val) + temp;
            solve(node->left,arr,left);
        }

        if(node->right != nullptr){
            string right = char(97 + node->right->val) + temp;
            solve(node->right,arr,right);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        vector<string> arr;
        if(root == nullptr){
            return "";
        }
        
        string temp = "";
        temp = temp + char(97 + root->val);

        solve(root,arr,temp);

        sort(arr.begin(),arr.end());

        return arr[0];
    }
};
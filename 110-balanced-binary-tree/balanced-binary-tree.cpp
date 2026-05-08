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

    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left=solve(root->left);
        int right=solve(root->right);

        if(left==INT_MAX || right==INT_MAX){
            return INT_MAX;
        }

        if(left-right>1 || right-left>1){
            return INT_MAX;
        }
        int ans=max(left,right)+1;
        return ans;
    }

    bool isBalanced(TreeNode* root) {

        int output=solve(root);
        if(output==INT_MAX){
            return false;
        }
        return true;
    }
};
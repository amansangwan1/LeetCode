/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val==q->val || root->val==p->val) return root;

        if(!((root->val>=p->val && root->val>=q->val)||(root->val<=p->val && root->val<=q->val))) return root;

        return (root->val<p->val)? solve(root->right,p,q):solve(root->left,p,q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};
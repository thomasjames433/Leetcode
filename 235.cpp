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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode *x=root;
            if(p->val >root->val && q->val> root->val)
                x=lowestCommonAncestor(root->right,p,q);
            
            else if(p->val <root->val && q->val< root->val)
                x=lowestCommonAncestor(root->left,p,q);
            
            return x;
        }
    };
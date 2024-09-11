/**
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    if(!root)
        return;
    flatten(root->left);
    flatten(root->right);

    struct TreeNode *temp=root->right;
    root->right=root->left;
    root->left=NULL;
    struct TreeNode *a=root;
    while(a->right)
        a=a->right;
    a->right=temp;

}
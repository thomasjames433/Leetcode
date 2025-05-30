/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool compare(struct TreeNode* a,struct TreeNode* b){
    if(a==NULL && b==NULL)
    return true;
    else if(a==NULL || b==NULL)
    return false;
    else if(a->val!=b->val)
    return false;
    return compare(a->left,b->right) && compare(a->right,b->left);
}
bool isSymmetric(struct TreeNode* root) {
    return compare(root->left,root->right);
}
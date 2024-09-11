/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* root,long int min,long int max){
    if(!root)
        return 1;
    if(root->val<=min || root->val>=max)
        return 0;
    else 
        return check(root->left,min,root->val) && check(root->right,root->val,max); 
}

bool isValidBST(struct TreeNode* root) {
    return check(root,LONG_MIN,LONG_MAX);
}
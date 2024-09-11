/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int inorder(struct TreeNode* root, int *k){
    if(!root)
    return -1;
    int a=inorder(root->left,k);
    if(*k==0)
        return a;
    (*k)--;
    if(*k==0)
        return root->val;
    return inorder(root->right,k);

}

int kthSmallest(struct TreeNode* root, int k) {
    int x=k;
    return inorder(root,&x);
}
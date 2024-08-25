/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void ps(int *a,struct TreeNode* root, int* rs){
    if(root){
        ps(a,root->left,rs);
        ps(a,root->right,rs);
        a[(*rs)++]=root->val;
    }
    return;
}
int* postorderTraversal(struct TreeNode* root, int* rs) {
    int *a=(int *)malloc(102*sizeof(int));
    *rs=0;
    ps(a,root,rs);
    return a;
}
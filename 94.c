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
void inorder(struct TreeNode *root, int **A,int *returnsize){
    if(root!=NULL){
        inorder(root->left, A,returnsize);
        (*A)[(*returnsize)]=root->val;
        (*returnsize)++;
        inorder(root->right,A,returnsize);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnsize) {
    int *A=(int*)malloc(100*sizeof(int));
    *returnsize=0;
    inorder(root,&A,returnsize);
    return A;
}
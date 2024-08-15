/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode *root,int low,int high, int *sum){
    if(root!=NULL){
        inorder(root->left, low,high,sum);
        if(root->val<= high && root->val>=low)
        (*sum)=(*sum)+root->val;
        inorder(root->right,low,high,  sum);
    }
}
int rangeSumBST(struct TreeNode* root, int low, int high) {
    int sum=0;
    inorder(root,low,high, &sum);
    return sum;
}
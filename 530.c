/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void checkmin(struct TreeNode*root,int *min,int *prev){
    if(!root)return;

    checkmin(root->left,min,prev);

    if(*prev!=-1){
        if(abs(root->val-*prev)<*min)
            *min=abs(root->val-*prev);
    }
    *prev=root->val;
    checkmin(root->right,min,prev);

}

int getMinimumDifference(struct TreeNode* root) {
    int min=1000000; int x=-1;
    checkmin(root,&min,&x);
    return min;
}
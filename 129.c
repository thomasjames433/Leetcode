/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void add(struct TreeNode *root,int *total,int*sum){
    if(root==NULL){
        // (*sum)+=0;
    }
    else if(root->left==NULL && root->right==NULL){
        (*total)=(*total)+(*sum)*10+root->val;
    }
    else{
        (*sum)=(*sum)*10+root->val;
        add(root->left,total,sum);
        add(root->right,total,sum);
        (*sum)=((*sum)-root->val)/10;
    }
}

int sumNumbers(struct TreeNode* root) {
    int total=0;int sum=0;
    add(root,&total,&sum);
    return total;
}
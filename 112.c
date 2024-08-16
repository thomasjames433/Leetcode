/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void issum(struct TreeNode* root, int target,int *sum,bool*abc){
    if(root==NULL){
        // (*sum)+=0;
    }
    else if(root->left==NULL && root->right==NULL){
        if(*sum+root->val==target)
            *abc=true;
        
    }
    else{
        (*sum)+=root->val;
        issum(root->left,target,sum,abc);
        issum(root->right,target,sum,abc);
        (*sum)-=root->val;
    }
    return;
}
bool hasPathSum(struct TreeNode* root, int target) {
    int sum=0;bool a=false;
    issum(root,target,&sum,&a);
    return a;
}
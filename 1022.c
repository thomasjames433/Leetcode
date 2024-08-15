/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void sum(struct TreeNode*root, int *tot,int *temp){
    
    if(root==NULL)
    return ;
    if(root->val==0)
    *temp*=2;
    else{
        *temp=*temp*2+1;
    }
    if(root->left==NULL && root->right==NULL){
        *tot+=*temp;
    }
    
    else{
        
        sum(root->left,tot,temp);
        sum(root->right,tot,temp);
    }
    if(root->val==0)
    *temp=*temp/2;
    else{
        *temp=(*temp-1)/2;
    }
}
int sumRootToLeaf(struct TreeNode* root) {
    int tot=0;int temp=0;
    sum(root,&tot,&temp);
    return tot;
}
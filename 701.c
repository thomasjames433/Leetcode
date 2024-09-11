/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *createnode(int val){
    struct TreeNode *temp=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->val=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct TreeNode *insertnode(struct TreeNode *root,int val){
    if(!root)
        return createnode(val);
    if(val>root->val ){
        root->right=insertnode(root->right,val);
    }
    
    else if(val<root->val ){
        root->left=insertnode(root->left,val);
    }
    return root;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    return insertnode(root,val);
}